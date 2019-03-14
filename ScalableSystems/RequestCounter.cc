/*
 * Count #of visitors in the past 1 minute [or 5 minutes, hour, all of the above]
 */
#include <vector>
#include <atomic>
#include <chrono>
#include <tuple>
#include <numeric>
#include <deque>
#include <thread>
#include <iostream>

using namespace std;

using Clock = std::chrono::system_clock;
using TimePoint = std::chrono::time_point<Clock>;

class Counter
{
 public:
  Counter(): m_frequencies(1000, 0), m_frequencies_seconds(60, 0), m_frequencies_minutes(60, 0), m_last_update_time() {}

  void increment();
  tuple<uint64_t, uint64_t, uint64_t> getCounts();


 private:
  vector<uint64_t>       m_frequencies;
  deque<uint64_t>        m_frequencies_seconds;
  deque<uint64_t>        m_frequencies_minutes;
  TimePoint              m_last_update_time;

};


void Counter::increment()
{
  using Ms = std::chrono::milliseconds;

  int ms_since_last_req = chrono::duration_cast<Ms>(Clock::now() - m_last_update_time).count();
  m_last_update_time = Clock::now();

  if (ms_since_last_req <= 999)
  {
    ++m_frequencies[ms_since_last_req];
    return;
  }

  uint64_t count_1sec = accumulate(m_frequencies.begin(), m_frequencies.end(), 0);
  fill(m_frequencies.begin(), m_frequencies.end(), 0);
  m_frequencies[0]++;


  if (m_frequencies_seconds.size() < 59)
  {
    m_frequencies_seconds.push_front(count_1sec);
    return;
  }
  
  uint64_t count_1min = *m_frequencies_seconds.begin();
  m_frequencies_seconds.pop_back();
  m_frequencies_seconds.push_front(count_1sec);


  if (m_frequencies_minutes.size() < 59)
  {
    m_frequencies_minutes.push_front(count_1min);
    return;
  }

  m_frequencies_minutes.pop_back();
  m_frequencies_minutes.push_front(count_1min);

}

tuple<uint64_t, uint64_t, uint64_t> Counter::getCounts()
{
  tuple<uint64_t, uint64_t, uint64_t> res;

  get<0>(res) = accumulate(m_frequencies.begin(), m_frequencies.end(), 0);
  get<1>(res) = accumulate(m_frequencies_seconds.begin(), m_frequencies_seconds.end(), 0) + get<0>(res);
  get<2>(res) = accumulate(m_frequencies_minutes.begin(), m_frequencies_minutes.end(), 0) + get<1>(res);
  
  return res;
}

int main()
{
  Counter counter;

  TimePoint startTime = Clock::now();

  using Seconds = chrono::seconds;

  TimePoint currTime;
  
  while (chrono::duration_cast<Seconds>((currTime = Clock::now()) - startTime).count() <= 1)
  {
    counter.increment();
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
  }

  auto res = counter.getCounts();
  cout << get<0>(res) << "," << get<1>(res) << "," << get<2>(res) << endl;
  return 0;
}

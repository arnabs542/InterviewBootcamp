/*
Comments :
Design a timer scheduler that can take a number of specified tasks and schedule
them for execution after specified time-interval delay.
What would be some of the design considerations to ensure efficiency, resiliency
and support for monitoring progress
*/

#include <sys/timerfd.h>
#include <sys/signalfd.h>
#include <signal.h>
#include <sys/select.h>

#include <iostream>
#include <chrono>
#include <unordered_map>
#include <utility>
#include <mutex>
#include <stdexcept>

#include "heap.hh"

using namespace std;

using Clock = std::chrono::high_resolution_clock;
using TimePoint = std::chrono::time_point<Clock>;

class TimerCallback
{
 public:
  void callback() = 0;
};

class TimerScheduler
{
 public:
  TimerScheduler();
  ~TimerScheduler();

  int registerTimeout(int timeMs, TimerCallback&);
  int cancelTimeout(TimerCallback&);
  void run();

 private:
  Heap<pair<TimerCallback, TimePoint>, compare > m_timeouts;
  unordered_map<TimerCallback, int>              m_callbackIndices;
  mutex                                          m_mutex;
  int                                            m_timerFd;
  int                                            m_signalFd;
};

//////////////////////////////// Implementation /////////////////////////////////////////
TimerScheduler::TimerScheduler()
{
  m_timerFd = timerfd_create(CLOCK_REALTIME, 0);
  if (m_timerFd == -1)
    throw runtime_error("timerfd_create");

	sigset_t mask;
	sigemptyset(&mask);
	sigaddset(&mask, SIGINT);
	sigaddset(&mask, SIGQUIT);

	/* Block signals so that they aren't handled
		 according to their default dispositions */

	if (sigprocmask(SIG_BLOCK, &mask, NULL) == -1)
  {
    int savedErrno = errno;
    throw runtime_error(strerror(savedErrno));
  }

	if ((m_signalFd = signalfd(-1, &mask, 0)) == -1)
  {
    int savedErrno = errno;
    throw runtime_error(strerror(savedErrno));
  }
}

TimerScheduler::~TimerScheduler()
{
  m_timerFd.close();
}

int TimerScheduler::registerTimeout(int timeMs, TimerCallback& callback)
{
  TimePoint now = Clock::now();
  TimePoint timeout(now + chrono::milliseconds(timeMs));

  {
    lock_guard<std::mutex> lock(m_mutex);
    auto it = m_callbackIndices.find(callback);
    if (it == m_callbackIndices.end())
      return -1;
    int index = m_timeouts.push(make_pair(callback, timeout));
    it->second = index;
  }

  return 0;
}

void TimerScheduler::cancelTimeout(const TimerCallback& callback)
{
  lock_guard<std::mutex> lock(m_mutex);
  auto it = m_callbackIndices.find(callback);
  if (it == m_callbackIndices.end())
    return -1;
  m_timeouts.remove(it->second);
  return 0;
}

void TimerScheduler::run()
{
  struct timespec timespec;
  timespec.tv_sec = 0;
  timespec.tv_nsec = 1000000; // 1 ms

  struct itimerspec timerspec;
  timerspec.it_interval = timespec; // interval for periodic timer
  timerspec.it_value = timespec;    // initial expiration

  if (timerfd_settime(m_timerFd, 0, &timerspec, NULL) == -1)
  {
    int errSaved = errno;
    throw runtime_error(strerror(errSaved));
  }

  uint64_t expired = 0;
  struct signalfd_siginfo siginfo;
  fd_set readFds;

  while (true)
  {
    FD_ZERO(&readFds);
    FD_SET(m_signalFd, &readFds);
    FD_SET(m_timerFd, &readFds);

    if (select(max(m_signalFd, m_timerFd)+1, &readFds, NULL, NULL, NULL) == -1)
    {
      int errSaved = errno;
      throw runtime_error(strerror(errSaved));
    }

    if (FD_ISSET(m_signalFd, &readFds))
    {
      cout << "exiting timer loop" << endl;
      break;
    }

    if (FD_ISSET(m_timerFd, &readFds))
    {
      if (read(m_timerFd, &expired, sizeof(uint64_t)) != sizeof(uint64_t))
      {
        int savedErrno = errno;
        throw runtime_error(strerror(savedErrno));
      }

      TimePoint now = Clock::now();
      TimerCallback *callback = nullptr;
      {
        lock_guard<std::mutex> lock(m_mutex);
        if (m_timeouts.top().second <= now)
        {
          callback = m_timeouts.top().second;
          m_timeouts.pop();
          m_callbackIndices.erase(callback);
        }
      }

      if (callback)
        callback.callback();
    }
  }
}

int main(int argc, char** argv)
{
  return 0;
}


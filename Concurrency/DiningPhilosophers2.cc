/*
Comments :
*/

#include <iostream>
#include <vector>
#include <mutex>
#include <chrono>
#include <thread>

using namespace std;


class DiningPhilosophers
{
  class Philosopher
  {
   public:
    Philosopher(int id, timed_mutex& left, timed_mutex& right) :
        m_id(id), m_leftChopstick(left), m_rightChopstick(right)
    {}

    void eat(int id)
    {
      if (m_leftChopstick.try_lock_for(std::chrono::milliseconds(1000)))
      {
        if (m_rightChopstick.try_lock_for(std::chrono::milliseconds(1000)))
        {
          cout << "Philosopher: " << id << " is eating" << endl;
          this_thread::sleep_for(std::chrono::seconds(5));
          m_rightChopstick.unlock();
          m_leftChopstick.unlock();
        }
        else
        {
          m_leftChopstick.unlock();
        }
      }
    }

   private:
    int m_id;
    timed_mutex& m_leftChopstick;
    timed_mutex& m_rightChopstick;
  };

 public: 

  DiningPhilosophers(size_t count) : count(count)
  {
    chopsticks = vector<std::timed_mutex*>(count, new timed_mutex());
    for (int i = 0; i < count; ++i)
    {
      timed_mutex *left = ((i==0) ? chopsticks[count-1] : chopsticks[count]);
      timed_mutex* right = ((i==count-1) ? chopsticks[0] : chopsticks[count]);
      Philosopher* p = new Philosopher(i+1, *left, *right);
      philosophers.push_back(p);
    }
  }

  ~DiningPhilosophers() {}

  void run()
  {
    for (int i = 0; i< count; ++i)
    {
      thread *t = new thread(&Philosopher::eat, *philosophers[i], i);
      threads.push_back(t);
    }

    for_each(threads.begin(), threads.end(), [](thread* th) {th->join();});

  }

  size_t                    count;
  vector<Philosopher*>      philosophers;
  vector<std::timed_mutex*> chopsticks;
  vector<thread*>           threads;
};

int main(int argc, char** argv)
{
  DiningPhilosophers dp(5);
  dp.run();
  return 0;
}


/*
Comments :
*/

#include <iostream>
#include <mutex>
#include <condition_variable>
#include <vector>

using namespace std;

class DiningPhilosophers
{

  struct Chopstick
  {
    Chopstick() : state(0) {}
    
    void available() 
    { 
      lock();
      state = 0; 
    }

    void inUse()
    {
      lock();
      state = 1;
    }

    int state;
    mutex lock;
    condition_variable isFree;
  };

  struct Philosopher
  {
    enum State { THINKING=0, EATING=1 };
    
    Philosopher(int pos) : m_pos(pos), m_state(THINKING) {}
    
    void  eat(vector<Chopstick>& chopsticks)
    {
      int left  = pos > 0 ? pos-1 : chopsticks.size()-1;
      int right = pos;

      // wait for left
      if (!chopsticks[left].isFree.waitFor(chopsticks[left].lock, relTime,
                                      [](chopsticks[left].state != 0)))
        goto EXIT;

      chopsticks[left].inUse();


      // wait for right
      if (!chopsticks[right].isFree.waitFor(chopsticks[right].lock, relTime,
                                       [](chopsticks[right].state != 0)))
        goto RELEASE_LEFT;
      
      chopsticks[right].inUse();

      m_state = EATING;
      cout << "Philosopher: " << m_pos << " eating now" << end;
      
      int randomSleep = rand();
      sleep(randomSleep);
      m_state = THINKING;

RELEASE_RIGHT:
      chopsticks[right].available();
      chopsticks[right].signal();
RELEASE_LEFT:
      chopsticks[left].available();
      chopsticks[left].signal();
EXIT:
      return;

    }

    int   m_pos;
    State m_state;
  };

  
  vector<Philosopher> philosophers;
  vector<Chopstick>   chopsticks;

};


int main(int argc, char** argv)
{
  return 0;
}


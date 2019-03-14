/*
Comments :
A latch is a synchronizer that acts like a gate. Until the latch reaches the
terminal state the gate is closed and no thread can pass, and in the terminal
state the gate opens allowing all threads to pass. Once the latch reaches
terminal state, it cannot change state again
*/

#include <iostream>
#include <thread>
#include <experimental/latch>

using namespace std;

latch start;
latch stop;

void thread_fn(int n)
{
  cout << "thread " << n << " waiting on latch " << endl;
  
  start.wait();

  cout << " thread " << n << " executing" << endl;

  sleep(1);
  stop.count_down();
  cout << " thread " << n << " exiting" << endl;
}


int main(int argc, char** argv)
{
  thread t1(thread_fn, 1);
  thread t2(thread_fn, 2);

  start = latch(1);
  cout << "Signaling threads to start" << endl;
  start.count_down();
  stop.wait();
  cout << "All thread exited " << endl;

  return 0;
}


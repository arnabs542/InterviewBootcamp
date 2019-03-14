/*
Comments :
*/

#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>

std::mutex m1;
std::condition_variable cv;
int i = 1;

using namespace std;

void oddFn()
{
  while (i <= 100) {
    unique_lock<mutex> lock(m1);
    cv.wait(lock, []{return i%2 == 1;});
    if (i%2 == 1 && i <= 100)
      cout << "odd " << i++ << endl;
    lock.unlock();
    cv.notify_one();
  }
}

void evenFn()
{
  while (i <= 100) {
    unique_lock<mutex> lock(m1);
    cv.wait(lock, []{return i%2 == 0;});

    if (i%2 == 0 && i <= 100)
      cout << "even " << i++ << endl;
    lock.unlock();
    cv.notify_one();
  }
}

int main(int argc, char** argv)
{
  thread evenTh(evenFn);
  thread oddTh(oddFn);

  evenTh.join();
  oddTh.join();
  return 0;
}


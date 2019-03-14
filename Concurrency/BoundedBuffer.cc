/*
Comments :
Design a bounded buffer for a producer/consumer problem
*/

#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <functional>

using namespace std;

class BoundedBuffer
{
 public:

  BoundedBuffer(size_t size) : m_maxSize(size) {cout << "Initialized" << endl;}
  
  void put(int val)
  {
    while (m_queue.size() >= m_maxSize)
    {
      cout << "waiting for space to free up" << endl;
      try
      {
        unique_lock<mutex> lock(m_mutex);
        m_cv.wait(lock, [=] {return this->size() >= this->m_maxSize;});
      }
      catch (const exception& e)
      { cout << "Caught exception while waiting to put" << endl; }
    }

    m_queue.push(val);
    m_cv.notify_one();
  }

  int get()
  {
    int val;
    while (m_queue.empty())
    {
      cout << "waiting for elements in queue " << endl;
      try
      {
        unique_lock<mutex> lock(m_mutex);
        m_cv.wait(lock, [=]{ return !(this->m_queue.empty()); });
      }
      catch (const exception& e)
      { cout << "Caught exception while waiting to get" << endl; }

      val = m_queue.front();
      m_queue.pop();
      m_cv.notify_one();
    }
    return val;
  }

  size_t size() { return m_queue.size(); }
  bool empty()  { return m_queue.empty(); }

 private:
      size_t              m_maxSize;
      queue<int>          m_queue;
      mutex               m_mutex;
      condition_variable  m_cv;
};

void producer(BoundedBuffer& bb, int offset)
{
  for (int i = 0; i < 10; ++i)
  {
    bb.put(i);
  }
}

void consumer(BoundedBuffer& bb)
{
  for (int i = 0; i < 10; ++i)
  {
    cout << bb.get() << endl;
  }
}

int main(int argc, char** argv)
{
  BoundedBuffer bb(10);
  vector<thread*> producers;
  vector<thread*> consumers;

  for (int i = 0; i < 10; ++i)
  {
    thread* t1 = new thread(producer, ref(bb), i);
    producers.push_back(t1);
  }
  for (int i = 0; i < 2; ++i)
  {
    thread* t1 = new thread(consumer, ref(bb));
    consumers.push_back(t1);
  }

  for (auto t: producers)
    t->join();
  for (auto t: consumers)
    t->join();

  return 0;
}


/*
Comments :
Create a thread pool and worker queues
Will need a
(a) a container to store created threads
(b) A standard interface class or interface class for the threads to use in
doing work. This might be an abstract class called Task with an execute() method
that does the work
(c) When a thread pool is handed a task it takes a thread from the container (or
waits for one to become available), hands it the task and meets the barrier
*/

#include <iostream>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <thread>
#include <queue>

using namespace std;

class Task
{
 public:
  virtual void execute()=0;
  virtual ~Task() {}
};

class Task1 : public Task
{
 public:
  virtual void info() { cout << "Executing task1 " << endl; }

  virtual void execute() { cout << "Hello from task1" << endl; }
};

class Task2 : public Task
{
 public:
  virtual void info() { cout << "Executing task2 " << endl; }

  virtual void execute() { cout << "Hello from task2" << endl; }
};

class QueuedTasks
{
 public:
  void addTask(Task* task)
  {
    lock_guard<mutex> lock(m_mutex);
    m_queue.push(task);
    m_cv.notify_one();
  }

  Task* getTask()
  {
    unique_lock<mutex> lock(m_mutex);
    while (m_queue.empty())
    {
      m_cv.wait(lock, [=]{ return !m_queue.empty(); });
    }
    Task* task = m_queue.front();
    m_queue.pop();
    return task;
  }

 private:
  queue<Task*>        m_queue;
  mutex               m_mutex;
  condition_variable  m_cv;
};


class ThreadPool
{
  static void threadFn(ThreadPool& ref)
  {
    while (true)
    {
      Task* task = ref.m_queue.getTask();
      task->execute();
    }
  }

 public:
  ThreadPool(size_t count, QueuedTasks& queue) : m_queue(queue)
  {
    for (int i = 0; i < count; ++i)
    {
      thread* th = new thread(ThreadPool::threadFn, std::ref(*this));
      m_threads.push_back(th);
    }
  }

 private:
  vector<thread*> m_threads;
  QueuedTasks&    m_queue;

};

int main(int argc, char** argv)
{
  QueuedTasks tasks;
  ThreadPool pool(2, tasks);

  Task* task1 = new Task1();
  Task* task2 = new Task2();
  tasks.addTask(task1);
  tasks.addTask(task2);
  while(1);
  return 0;
}


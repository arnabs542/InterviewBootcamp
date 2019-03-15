#ifndef __sorted_stack__
#define __sorted_stack__

#include <stack>

template <typename T>
class sorted_stack
{
 public:
  sorted_stack() : m_stack() {}
  ~sorted_stack() {}

  void    push(T& elem);
  void    pop()   { m_stack.pop();          }
  T       peek()  { return m_stack.top();   }
  bool    empty() { return m_stack.empty(); }

 private:
  std::stack<T> m_stack;
};


///// Implementation /////
template <typename T>
void sorted_stack<T>::push(T& val)
{
  std::stack<T> tmp;

  while (!m_stack.empty() && m_stack.top() < val)
  {
    T elem = m_stack.top(); m_stack.pop();
    tmp.push(elem);
  }

  m_stack.push(val);
  while (!tmp.empty())
  {
    m_stack.push(tmp.top());
    tmp.pop();
  }
}

#endif

#ifndef __set_of_stacks__
#define __set_of_stacks__

#include <stack>
#include <vector>

template <typename T>
class set_of_stacks
{
 public:
  set_of_stacks(unsigned threshold) : m_threshold(threshold) {}
  ~set_of_stacks()
  {
    for (auto st : m_stacks)
      delete st;
  }

  void push(T&);
  T    pop();
  bool empty();
  T    peek();

  typedef std::stack<T> stack_t;
  typedef stack_t*      stack_ptr_t;

 private:
  unsigned                      m_threshold;
  std::vector<stack_ptr_t>      m_stacks;
};



//////////////////// Implementation ///////////////////////////
template<typename T>
void set_of_stacks<T>::push(T& elem)
{
  if (m_stacks.empty() || m_stacks.back()->size() == m_threshold) 
  {
    stack_ptr_t stack = new stack_t;
    m_stacks.push_back(stack);
  }

  auto curr_stack = m_stacks.back();
  curr_stack->push(elem);
}

template <typename T>
T set_of_stacks<T>::pop()
{
  T elem = m_stacks.back()->top();
  m_stacks.back()->pop();

  if (m_stacks.back()->empty())
  {
    auto st = m_stacks.back();
    m_stacks.pop_back();
    delete st;
  }

  return elem;
}

template <typename T>
bool set_of_stacks<T>::empty()
{
  return m_stacks.empty();
}

template <typename T>
T set_of_stacks<T>::peek()
{
  return m_stacks.back()->top();
}

#endif

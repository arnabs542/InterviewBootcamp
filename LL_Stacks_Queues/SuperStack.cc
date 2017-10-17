/*
Comments :
implement a simple stack that implements the following commands and performs
operations associated with them:
push k : Push integer K onto top of stack
pop : Pop the top element from the stack
inc e k : Add k to each of the bottom e elements of the stack
*/

#include <iostream>
#include <stack>
#include <cassert>
#include <vector>

using namespace std;

template <typename T>
class SuperStack
{
 public:
  
  SuperStack() {}
  ~SuperStack() {}

  // Interface
  void     pop();
  void     push(const T& val);
  bool     empty();
  const T& top();

  // Add k to bottom e elements of stack
  void inc (int k, int e);

 private:
  stack<T> s1;
  stack<T> s2;
};

template <typename T>
void SuperStack<T>::pop()              { s1.pop(); }

template <typename T>
void SuperStack<T>::push(const T& val) { s1.push(val); }

template <typename T>
bool SuperStack<T>::empty()            { return s1.empty(); }

template <typename T>
const T& SuperStack<T>::top()          { return s1.top();   }

template <typename T>
void SuperStack<T>::inc(int e, int k) 
{
  while (!s1.empty())
  {
    s2.push(s1.top());
    s1.pop();
  }

  for (int i = 1; i <= e && !s2.empty(); ++i)
  {
    T val = s2.top();
    s1.push(val + k);
    s2.pop();
  }

  while (!s2.empty())
  {
    s1.push(s2.top());
    s2.pop();
  }
}

void superStack(vector < string > operations) {

  SuperStack<int> st;

  for (auto const& strOp : operations)
  {
    if (strOp.compare(0, 4, "push") == 0)
    {
      int val = atoi(strOp.substr(5, strOp.length()-5).c_str());
      st.push(val);
    }
    else if (strOp.compare(0, 4, "pop") == 0)
    {
      assert(!st.empty());
      st.pop();
    }
    else if (strOp.compare(0, 3, "inc") == 0)
    {
      int begin = 4; int end = 0;
      int i = begin;
      while (i < strOp.length() && strOp[i] >= '0' && strOp[i] <= '9')
        ++i;
      end = i-1;
      int e = atoi(strOp.substr(begin, end-begin+1).c_str());

      begin = end+2;
      assert(strOp.length() > begin);
      
      int k = atoi(strOp.substr(begin, end-begin+1).c_str());
      st.inc(e, k);
    }
  
    if (!st.empty())
      cout << st.top() << endl;
    else
      cout << "EMPTY" << endl;
  }
}

int main(int argc, char** argv)
{
  vector<string> operations = {"push -36", "push 20", "pop", "push -9", "pop",
    "push -53", "pop", "inc 1 -17"};
  superStack(operations);
  return 0;
}


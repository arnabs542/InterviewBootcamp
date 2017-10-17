/*
Comments :
*/

#include <iostream>
#include <stack>

using namespace std;

template<typename T>
class MyStack
{
    public:
    MyStack() :
        myStack(),
        minStack()
    {}
    
    ~MyStack() {}
    
    const T* getMinimum() 
    {
      if (minStack.empty())
        return nullptr;

      return &minStack.top();
    }
    
    void push(const T& val)
    {
        myStack.push(val);
        if ( minStack.empty() || *getMinimum() > val)
            minStack.push(val);
    }
    
    void pop()
    {
      if (myStack.empty())
        return;

      if (myStack.top() == *getMinimum())
        minStack.pop();
      myStack.pop();
    }
    
    const T& top()
    {
        return myStack.top();
    }
    
    bool empty()
    {
        return myStack.empty();
    }
    
    size_t size()
    {
        return myStack.size();
    }
    
    
    private:
    stack<T> myStack;
    stack<T> minStack;
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    MyStack<int> s;
    
    s.push(1); s.push(5); s.push(3); s.push(0);
    s.pop(); s.pop(); s.pop(); s.pop();
    if (s.getMinimum())
      cout << *s.getMinimum()  << endl;
    else
      cout << "null" << endl;
    return 0;
}


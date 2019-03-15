#include <iostream>
#include <stack>

using namespace std;



void towersOfHanoi(stack<int>& fromStack, stack<int>& toStack, stack<int>& usingStack, int count)
{
  if (count == 0)
    return;

  cout << fromStack.size() << "," << toStack.size() << "," << usingStack.size() << endl;
  towersOfHanoi(fromStack, usingStack, toStack, count-1);
  toStack.push(fromStack.top());
  fromStack.pop();
  towersOfHanoi(usingStack, toStack, fromStack, count-1);
}

int main()
{
  stack<int> st1, st2, st3;

  for (int i=5; i >0; --i)
    st1.push(i);

  int count=5;
  towersOfHanoi(st1, st2, st3, count);


  while(!st2.empty())
  {
    cout << st2.top() << endl;
    st2.pop();
  }

  return 0;
}

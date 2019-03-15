#include <iostream>

#include "SortStack.hh"

int main()
{
  sorted_stack<int> ss;

  for (int i = 1; i <= 10; ++i)
  {
    ss.push(i);
  }

  while (!ss.empty()) {
    std::cout << ss.peek() << std::endl;
    ss.pop();
  }
  return 0;
}

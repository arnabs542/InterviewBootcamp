#include <iostream>
#include "SetOfStacks.hh"

int main()
{
  set_of_stacks<int> stacks(3);

  for (int i=1; i <= 9; ++i)
    stacks.push(i);

  while (!stacks.empty()) {
    std::cout << stacks.peek() << std::endl;
    stacks.pop();
  }

  return 0;
}


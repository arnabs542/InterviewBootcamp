#include <iostream>
#include <vector>

int main()
{
  std::vector<int> a(10, 0);
  std::cout << a[-1] << std::endl;
  return 0;
}

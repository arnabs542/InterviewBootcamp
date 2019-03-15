#include <iostream>
#include <string>

long recursiveMultiply(int a, int b)
{
  if (b == 1)
    return a;

  int half = b/2;

  
  int res = recursiveMultiply(a, half);
  if (b%2)
    return res + res + a;
  return res + res;
}


int main(int argc, char** argv)
{

  std::cout << recursiveMultiply(std::stoi(argv[1]), std::stoi(argv[2])) << std::endl;

  return 0;
}


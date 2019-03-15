
#include <iostream>
#include <stdlib.h>

using std::cout;
using std::endl;


void getNthFibonacci(int N)
{

  long a = 0;
  long b = 1;

  if (N <= 1) {
    if (N==0)
      cout << a  << endl;
    else
      cout << b << endl;
    return;
  }

  long c;
  for (int i = 2; i <= N; ++i)
  {
    c = a + b;
    a = b;
    b = c;
  }

  cout << c << endl;
}


int main(int argc, char** argv)
{
  getNthFibonacci(atoi(argv[1]));

  return 0;
}

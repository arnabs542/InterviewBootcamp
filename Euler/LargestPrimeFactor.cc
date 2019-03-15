#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

int largestPrime()
{
  long num = 600851475143;
  int lastFactor = 1;

  if ((num % 2) == 0) {
      
    lastFactor = 2;

    while ((num % 2) == 0) {
      num /= 2;
    }
  }

  long maxFactor = sqrt(num);
  
  for (long factor=3; num > 1 && factor <= maxFactor; factor += 2)
  {
    if ((num % factor) == 0) {
      lastFactor = factor;
      while ((num % factor) == 0) {
        num /= factor;
      }
    }
  }

  return (num == 1)? lastFactor : num;
}

int main()
{
  cout << largestPrime() << endl;

  return 0;
}

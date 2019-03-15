/*
 * A palindromic number reads the same both ways. The largest palindrome 
 * made from the product of two 2-digit numbers is 9009 = 91 × 99.
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */

#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(long num)
{
//cout << "checking: " << num << endl;
  vector<int> table;

  while(num)
  {
    table.push_back(num%10);
    num /= 10;
  }

  int i = 0, j = table.size()-1;

  while (i <= j)
  {
    if (table[i] != table[j])
      return false;
    ++i; --j;
  }

  return true;
}

long largestPalindrome()
{
  long smallest = 100;
  long largest = 999;
  long res = 0;

  for (int i = largest; i >= smallest ; --i)
  {
    for (int j = largest; j >= smallest; --j)
    {
      long product = i * j;
      if (isPalindrome(product))
        res = max(res, product);
    }
  }

  return res;
}

int main()
{
cout << largestPalindrome() << endl;
//assert(isPalindrome(1001));
//assert(isPalindrome(9009));
  return 0;
}

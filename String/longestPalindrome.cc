/*
Comments :
*/

#include <iostream>
#include <string>
#include <limits>

using namespace std;

void allSubstringsinDescendingOrder(const string& inStr)
{
  for (int len=inStr.size(); len > 0; --len)
  {
    for (int b=0; b < inStr.size(); ++b)
    {
      int e = b + len - 1;
      if (e < inStr.size())
        cout << b << " " << e << " " << inStr.substr(b, e-b+1) << endl;
    }
  }
}

int maxLenPalindrome(const string& inStr)
{
  int maxLen = numeric_limits<int>::min();
  int left, right;
  string res;

  // Odd length palindrome, the center is a character
  for (int c = 0; c < inStr.size(); ++c) 
  {
    for (left=c-1, right=c+1; left >= 0 && right < inStr.size() && inStr[left] ==
         inStr[right]; --left, ++right);
    if ((right-1) - (left+1) + 1 > maxLen)
    {
      maxLen = (right-1)-(left+1) + 1;
      res = inStr.substr(left+1, maxLen);
      //maxLen = max(maxLen, (right-1)-(left+1)); // the -1 and +1 is because we
      //exit the above loop after either overshooting the limits or not meeting the
      //condition that chars are equal
    }
  }

  // Even length palindrome, the center is an empty space
  for (int c=0; c < inStr.size(); ++c)
  {
    for (left=c, right=c+1; left >= 0 && right < inStr.size() && inStr[left] ==
         inStr[right]; --left, ++right);
    if ((right-1) - (left+1) + 1 > maxLen)
    {
      maxLen = (right-1)-(left+1) + 1;
      res = inStr.substr(left+1, maxLen);
    }
  }

  cout << res << endl;
  return maxLen;
}

int main(int argc, char** argv)
{
  //allSubstringsinDescendingOrder("abc");
  cout << maxLenPalindrome("cbbd") << endl;
  return 0;
}


/*
Comments :
Find the longest palindrome in a string
Find all subtrings of string in descending order
*/

#include <iostream>

using namespace std;

//  Complexity : O(n ^ 3)
string longestPalindrome(const string& str)
{
  for (int len = str.size(); len > 0; --len)
  {
    for (int b = 0; b <= s.size(); ++b)
      int e = b + len;
    string s = str.substr(b, e);
    if(isPalindrome(s))
      return s;
  }
}

// Complexity : O(n^2)
string longestPalindrome(const string& str)
{
  int maxSize = numeri_limits<int>::min();
  int l, r;

  for (int c = 0; c < str.length(); c++)
  {
    for (l=c-1, r=c+1; l>0 && r < str.length() && str[l] == str[r]; l--, r++);

    if ((r-1) - (l+1) > maxSize)
      maxSize = (r-1) - (l+1);

    for (c=0; c < str.length(); ++c)
    {
      for (l=c, r=c+1, l>=0 && r < s.length() && str[l] == str[r]; l--, r++);
      
      if ((r-1) - (l+1) > maxSize)
        maxSize = (r-1) - (l+1);
    }
  }

  return maxSize;
}



int main(int argc, char** argv)
{
  return 0;
}


/*
 * Find longest palindrome in string
 */

#include <string>
#include <iostream>
#include <cassert>

using namespace std;

bool isPalindrome(const string& str)
{
  int begin=0, end=str.size()-1;

  while (begin < end)
  {
    if (str[begin++] != str[end--])
      return false;
  }
  return true;
}

string longestPalindromeBrute(const string& str)
{
  int length = str.size();

  for (int len=length; len > 0; --len)
  {
    for(int begin=0; begin < (length - len); ++begin)
    {
      string s = str.substr(begin, len);
      if (isPalindrome(s))
        return s;
    }
  }

  return "";
}

string longestPalindrome(const string& str)
{
  int maxLen = 0;
  string palindrome;

  // Odd length
  for (int mid=0; mid < str.size(); ++mid)
  {
    int left = mid-1, right = mid+1;
    while (left >= 0 && right < str.size() && str[left] == str[right])
    {--left; ++right;}

    ++left; --right;
    if((right - left + 1) > maxLen) {
      maxLen = right - left + 1;
      palindrome = str.substr(left, maxLen);
    }
  }

  // Even length
  for (int mid=0; mid < str.size(); ++mid)
  {
    int left = mid, right = mid+1;
    while (left >= 0 && right < str.size() && str[left] == str[right])
    {--left; ++right;}
    ++left; --right;
    if((right - left + 1) > maxLen) {
      maxLen = right - left + 1;
      palindrome = str.substr(left, maxLen);
    }
  }

  cout << palindrome << endl;
  return palindrome;
}


int main()
{
  assert(longestPalindrome("xyzaabaadef") == "aabaa");
  assert(longestPalindrome("asaaacdcaaaxfdf") == "aaacdcaaa");
  assert(longestPalindrome("abc") == "a");

  return 0;
}

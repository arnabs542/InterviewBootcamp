/*
 * Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:
Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
*/

#include <map>
#include <string>

using namespace std;

int longestPalindrome(string str) {
  map<char, int> freq;

  for (auto c: str)
  {
    if (freq.count(c))
      ++freq[c];
    else
      freq[c] = 1;
  }

  int odd = 0;
  int res = 0;
  for (auto kv: freq) {
    if ((kv.second % 2) == 0) {
      res += kv.second;
    }
    else  {
      if (kv.second > 2)
        res += (kv.second /2) * 2;
      ++odd;
    }
  }

  return (odd)? (res+1) : res; 
}

/*
 * Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.

For example, with A = "abcd" and B = "cdabcdab".
Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").

A = "abc" and B = "cabca"
Return 3

A = "abc" and B = "a"
Return 1

Note:
The length of A and B will be between 1 and 10000.

*/

#include <iostream>
#include <string>
#include <cmath>
#include <cassert>

using namespace std;

// Is s2 a substrung of s1
bool isSubstr(const string& s1, const string& s2)
{
  if (s2.size() > s1.size())
    return false;

  int i=0, j=0;

  while (i < s1.size() && j < s2.size())
  {
    while(i < s1.size() && s1[i] != s2[j])
      ++i;

    while(i < s1.size() && j < s2.size() && s1[i] == s2[j]) {
      ++i; ++j;
    }

    if (j != s2.size()) // didnt find the entire string, restart
      j=0;
  }

  return j == s2.size();
}

int repeatedStringMatch(string A, string B)
{
  int len1 = A.size();
  int len2 = B.size();

  int min = ceil(float(len2)/ len1);
  int minCopy = min;

  string str1;
  while(minCopy--)
    str1 += A;

 string str2 = str1 + A; 
  cout << str2 << endl;

 if (isSubstr(str1,B))
   return min;
 if (isSubstr(str2,B))
   return min+1;
 return -1;
}

int main()
{
  assert( repeatedStringMatch("abcd", "cdabcdab") == 3);
  assert( repeatedStringMatch("abc", "cabca") == 3);
  assert( repeatedStringMatch("abc", "a") == 1);
  assert( repeatedStringMatch("abc", "d") == -1);
  return 0;
}

/*
Comments :
Given a string, find the length of the longest substring T that contains at most
two distinct characters.

Solution : Template on leetCode here:
https://discuss.leetcode.com/topic/30941/here-is-a-10-line-template-that-can-solve-most-substring-problems/2
Follow the same template of maintaining two pointers left and right. A map keeps
account of the frequency of characters in the window [left, right]. A count
variable maintains a count of the unique characters in the same window. Whenever
count > 2, we are sure that in the window [left, right-1] we had <= 2 unique
characters. This is because : whenver count > 2, we run a loop that keeps
decreasing the window from the left as long as count > 2.
Every time we hit count > 2, we update the str if left-right > size.
Outside the loop, we again need to check if we need to update our estimate of
the longest string, since when we looked at the last character in the string the
value of could be <= 2 in which case we did not account for this last window of
the string which ends at the last char in the string
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

string longestSub(const string& strText)
{
  int left=0, right = 0; // indices to the window in the string we are considering
  int count = 0;
  map<char, int> m;
  int size = -1;
  string str;

  while (right < strText.size())
  {
    char c = strText[right];

    if (m.find(c) == m.end())
    {
      m[c] = 1;
      ++count;
    }
    else
    {
      m[c]++;
    }

    if (count > 2 && size < (right-left))
    {
      str = strText.substr(left, right-left);
      size = right - left;
    }

    while (count > 2)
    {
      if (--m[strText[left]] == 0 )
        --count;
      ++left;
    }

    ++right;
  }

  if (count <= 2 && size < (right - left))
  {
    str = strText.substr(left, right-left);
  }

  return str;
}

int main(int argc, char** argv)
{
  cout << longestSub("eceba") << endl;
  return 0;
}


/*
Comments :
Given a string S and a string T, find the minimum window in S which contains all
the characters in T
eg.
S="AYZABOBECODXBANC"
T="ABC"

Minimum window is "BANC" which contains the letter A B and C
-> If no such window exists, then return an empty string
-> If there are multiple minumum windows of the same length, then return any one
-> characters may be repeated

Solution summary:
https://discuss.leetcode.com/topic/30941/here-is-a-10-line-template-that-can-solve-most-substring-problems
*/

#include <iostream>
#include <set>
#include <utility>
#include <map>
#include <string>

using namespace std;


string MinWindow(const string& strText, const string& strCharacters)
{
  map<char, int> myMap;
  map<char, int> freqMap;

  for (auto c : strCharacters) 
  {
    myMap[c] = 0;
    freqMap[c] = 0;
  }
  for (auto c : strCharacters) 
    freqMap[c]++;

  int left = 0, right = 0;
  int count = 0;
  int size = numeric_limits<int>::max();
  string str;

  while (right < strText.size())
  {
    char c = strText[right];
    if (myMap.find(c) != myMap.end())
    {
      myMap[c]++;
      if (myMap[c] == freqMap[c]) {
        ++count;
      }
    }

    while (count == myMap.size())
    {
      if (myMap.find(strText[left]) != myMap.end())
      {
        if (--myMap[strText[left]] < freqMap[strText[left]]) 
        {
          if (size > right - left + 1)
          {
            size = right - left + 1;
            str = strText.substr(left, right-left+1);
          }
          --count;
        }
      }
      ++left;
    }

    ++right;
  }

  return str;
}

int main(int argc, char** argv)
{
  cout << MinWindow("acdbddddddddaaaaaaaadabbba", "baad") << endl;
  return 0;
}


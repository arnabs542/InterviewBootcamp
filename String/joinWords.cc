/*
Comments :

Given a list of unique words, find all pairs of distinct indices (i, j) in the
given list, so that the concatenation of the two words, i.e. words[i] + words[j]
is a palindrome.

Example 1:
Given words = ["bat", "tab", "cat"]
Return [[0, 1], [1, 0]]
The palindromes are ["battab", "tabbat"]
Example 2:
Given words = ["abcd", "dcba", "lls", "s", "sssll"]
Return [[0, 1], [1, 0], [3, 2], [2, 4]]
The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]

https://leetcode.com/problems/palindrome-pairs/description/

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool isPalindrome(const string& str)
{
  int i = 0, j = str.size()-1;

  while (i < j)
  {
    if (str[i++] != str[j--])
      return false;
  }
  return true;
}

vector<vector<int> > palindromePairs(const vector<string>& words)
{
  unordered_map<string, int> table;
  vector<vector<int> > res;

  if (words.size() <= 1)
    return res;
  
  // Initialize
  int i = 0;
  for (auto s : words)
    table[s] = i++;

  for (int i = 0; i < words.size(); ++i)
  {
    for (int count = 0; count <= words[i].size(); ++count)
    {
      string prefix = words[i].substr(0, count);
      string suffix = words[i].substr(count, words[i].size()-count);

      if (isPalindrome(prefix))
      {
        reverse(suffix.begin(), suffix.end());
        unordered_map<string, int>::iterator  it;
        if (( it = table.find(suffix)) != table.end())
        {
          res.push_back({it->second, i});
        }

      }
      if (!suffix.empty() && isPalindrome(suffix))
      {
        reverse(prefix.begin(), prefix.end());
        unordered_map<string, int>::iterator  it;
        if ((it = table.find(prefix)) != table.end())
        {
          res.push_back({i, it->second});
        }
      }
    }
  }

  return res;
}

int main(int argc, char** argv)
{
  vector<vector<string> > words = {{"bat", "tab", "cat"}, {"ab", "deedba"
  },{"ant", "cat", "dog"}};

  for (auto w : words)
  {

    vector<vector<int> > res = palindromePairs(w);
    for (auto indexes : res)
      cout << w[indexes[0]] << "," <<  w[indexes[1]] << " ";
          cout << endl;
  }

  return 0;
}


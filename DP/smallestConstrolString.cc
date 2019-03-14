/*
Comments :
*/

#include <iostream>
#include <string>

using namespace std;

// Find 

string smallestConstrolSubstring(const string& str, set<char> charSet)
{
  set<char> tmp(charSet);

  for (int len =  0; len <= str.length();  --len)
  {
    for (int b = 0; b < str.length(); ++b)
    {
      string substr  = str.substr(b, len);
      for (auto c : tmp)
        if (substr.contains(c))
          tmp.remove(c);
    }
  }
  if (tmp.size() == 0 && e-b < min)
    min = e-b;
}

pair<int, int> smallestControlSubstring(const string& str, set<char> q)
{
  int b, e;

  // Find the location of the first characher we find in q
  for (b = 0; b < str.length(); ++b)
  {
    if (q.contains(str[b]))
      break;
  }
  if (b == str.length())
    return make_pair(-1, -1);

  if (q.size() == 1)
    return make_pair(b, b);

  int minVal = numeric_limits<int>::max();

  pair<int, int> res;
  map<char, int> charFreq;
  for (auto c: q)
    charFreq.emplace(c,0);
  charFreq[str[b]]++;
  int missing = q.size() - 1;

  for (e = b + 1; e < str.length(); ++e)
  {
    if (q.find(str[e]) == q.end())
      continue;
    q[str[e]]++;
    if (q[str[e]] == 1)
      --missing;  // found a new char from the set
    if (missing > 0)
      continue;
    for (; b < e; b++)  // shrinking loop
    {
      char c = str[b];
      if (q.find(c) != q.end())
        charFreq[c]—;
      if (charFreq[c] == 0)
      {
        if ((e - b + 1) < min)
        {
          res.first = b;
          res.second = e;
        }
        ++b;
        break;
      }
    }
  }
}

int main(int argc, char** argv)
{
  return 0;
}


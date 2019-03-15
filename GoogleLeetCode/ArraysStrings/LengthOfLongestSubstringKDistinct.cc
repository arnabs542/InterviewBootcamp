#include <iostream>
#include <string>
#include <map>


using namespace std;

int lengthOfLongestSubstringKDistinct(string s, int k) {
  int res = 0;

  if (s.empty())
    return res;

  int begin=0; int end=1;
  map<char, int> m;
  m[s[begin]] = 1;

  while (begin <= end && end <= s.size())
  {
    while (m.size() <= k && end <= s.size()) {
      char ch = s[end];

      if (m.find(ch) == m.end() && m.size() == k)
        break;

      if (m.count(ch))
        ++m[ch];
      else
        m[ch] = 1;
      ++end;
    }

    if (m.size() <= k)
      res = max(res, end-begin);

    int count = m.count(s[begin]);
    if (count == 1)
      m.erase(s[begin]);
    else
      --m[s[begin]];
    ++begin;
  }

  return res;
}

int main()
{
  assert(lengthOfLongestSubstringKDistinct("eecd", 2) == 3);
  assert(lengthOfLongestSubstringKDistinct("eceedc", 3) == 6);

  return 0;
}

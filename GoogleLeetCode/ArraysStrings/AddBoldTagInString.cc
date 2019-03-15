/*
 Given a string s and a list of strings dict, you need to add a closed pair of bold tag <b> and </b> to wrap the substrings in s that exist in dict. If two such substrings overlap, you need to wrap them together by only one pair of closed bold tag. Also, if two substrings wrapped by bold tags are consecutive, you need to combine them.
Example 1:
Input: 
s = "abcxyz123"
dict = ["abc","123"]
Output:
"<b>abc</b>xyz<b>123</b>"
Example 2:
Input: 
s = "aaabbcc"
dict = ["aaa","aab","bc"]
Output:
"<b>aaabbc</b>c"
Note:
The given dict won't contain duplicates, and its length won't exceed 100.
All the strings in input have length in range [1, 1000].

Input:
"qrzjsorbkmyzzzvoqxefvxkcwtpkhzbakuufbpgdkykmojwuennrjeciqvvacpzrrczfhxnsmginzwinzihpomxtmweyyzzmgcoiupjnidphvzlnxtcogufozlenjfvokztghwckzyvmktduqkizixzxpanjwrdeudjyftxksjgdklwxrhmudhrtemuvelykqaafzlqmennttkighcdxfozdcoqkyshhajipnsdrljrnlwmyjuwxsebpqm"
["qr","zj","so","rb","km","yz","zz","vo","qx","ef","vx","kc","wt","pk"]
Output:
"<b>qrzjsorbkmyzz</b>z<b>voqxefvxkcwtpk</b>hzbakuufbpgdky<b>km</b>ojwuennrjeciqvvacpzrrczfhxnsmginzwinzihpomxtmwey<b>yzz</b>mgcoiupjnidphvzlnxtcogufozlenjf<b>vo</b>kztghwckzyvmktduqkizixzxpanjwrdeudjyftxksjgdklwxrhmudhrtemuvelykqaafzlqmennttkighcdxfozdcoqkyshhajipnsdrljrnlwmyjuwxsebpqm"
Expected:
"<b>qrzjsorbkmyzzzvoqxefvxkcwtpk</b>hzbakuufbpgdky<b>km</b>ojwuennrjeciqvvacpzrrczfhxnsmginzwinzihpomxtmwey<b>yzz</b>mgcoiupjnidphvzlnxtcogufozlenjf<b>vo</b>kztghwckzyvmktduqkizixzxpanjwrdeudjyftxksjgdklwxrhmudhrtemuvelykqaafzlqmennttkighcdxfozdcoqkyshhajipnsdrljrnlwmyjuwxsebpqm"
*/
#include <string>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> Interval;
typedef vector<Interval> Intervals;

void mergeIntervals(Intervals& intervals, Intervals& merged)
{
  Interval curr = intervals[0];

  for (int i=1; i < intervals.size(); ++i)
  {
    if ((intervals[i].first <= curr.second) || (intervals[i].first == curr.second+1)) {
      curr.second = max(curr.second, intervals[i].second);
    } else {
      merged.push_back(curr);
      curr = intervals[i];
    }
  }
  merged.push_back(curr);
}

string addBoldTag(string& s, vector<string>& dict)
{

  if (s.empty() || dict.empty())
    return s;

  Intervals intervals;

  for (auto sd: dict) { // find each occurence of string sd in the given string
    int pos=0;
    while (pos  <= s.size() - sd.size())
    {
      pos = s.find(sd, pos);

      if (pos == string::npos)
        break;

      intervals.push_back(Interval(pos, pos+sd.size()-1));
      pos += 1;
    }
  }

  struct {
    bool operator()(const Interval& a, const Interval& b)
    {
      return (a.first == b.first) ? (a.second < b.second) : (a.first < b.first);
    }
  }mycompare;

  sort(intervals.begin(), intervals.end(), mycompare);

  for (auto intv: intervals)
    cout << intv.first << "," << intv.second << endl;

  Intervals merged;
  mergeIntervals(intervals, merged);

  int index=0;
  string res;
  for (int i=0; i < merged.size();)
  {
    if(merged[i].first == index) {
      res += "<b>";
      while (index < s.size() && index <= merged[i].second) {
        res.push_back(s[index]);
        ++index;
      }
      res += "</b>";
      ++i;
    } else {
      res.push_back(s[index]);
      ++index;
    }
  }
  while (index < s.size())
    res.push_back(s[index++]);

  return res;
}

int main()
{
#if 0
  string str = "aaabbcc";
  vector<string> dict = {"aaa","aab","bc"};

  cout << addBoldTag(str, dict) << endl;
#endif
  string str = "abcxyz123";
  vector<string> dict = {"abc","123"};
  cout << addBoldTag(str, dict) << endl;
  
  return 0;
}

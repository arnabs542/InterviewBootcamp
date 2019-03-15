#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::endl;

struct
{
  bool operator()(const string& str1, const string& str2)
  {
    string s1 = str1;
    string s2 = str2;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    return s1.compare(s2) < 0;
  }
} anagramCompare;

void groupAnagrams(vector<string>& array)
{
  sort(array.begin(), array.end(), anagramCompare);

  for (auto str: array)
    cout << str << ",";
  cout << endl;
}

int main()
{
  vector<string>  array = {"cat", "abc", "def", "atc", "cde", "cab", "fed"};

  groupAnagrams(array);
  return 0;
}

/*
Comments :
You have a dictionary of words and two strings A and B
How can you convert A to B by changing just one character at a time and making
sure all the intermediate words are in the dictionary.

Solution Summary : Construct a graph, where nodes are the words and the
neighbors are words that differ from the given word by one character. Then find
a path (shortest path is also a path) from word A to word B in this graph

Cost of constructing this graph : O(n x n x m), where n is the number of words
in dictionary and m is the length of the word.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

unordered_map<string, vector<string> > graph;
vector<string> dictionary = {"cat", "bat", "hat", "bad", "had"};

int diffChars(const string& s1, const string& s2)
{
  int count = 0;
  int i = 0;

  while (i < s1.size() && i < s2.size())
  {
    if (s1[i] != s2[i])
      ++count;
    ++i;
  }

  if (i < s1.size())
    count += s1.size() - i; 
  if (i < s2.size())
    count += s2.size() - i;

  return count;
}

void constructGraph()
{
  for (int i = 0; i < dictionary.size(); ++i)
    for (int j = 0; j < dictionary.size(); ++j)
    {
      if (i == j) continue;
      if (diffChars(dictionary[i], dictionary[j]) == 1)
        graph[dictionary[i]].push_back(dictionary[j]);
    }
}

void bfs(const string& str1, const string& str2, vector<string>& res)
{
  queue<string> q;
  unordered_map<string, string> backref;

  q.push(str1);
  backref[str1]="";

  while(!q.empty())
  {
    string str = q.front();
    q.pop();
    if (str == str2) break;

    for (auto const n : graph[str])
    {
      if (backref.find(n) != backref.end())
        continue;
      q.push(n);
      backref[n] = str;
    }
  }

  string str = str2;
  res.push_back(str2);
  while (str != str1)
  {
    res.push_back(backref[str]);
    str = backref[str];
  }

  reverse(res.begin(), res.end());

}

int main(int argc, char** argv)
{
#if 0
  fstream fs;
  fs.open("/usr/share/dict/words", fstream::in);
  string str;
  while (fs >> str) 
    dictionary.push_back(str);
#endif

  vector<string> res;

  constructGraph();
  bfs("bat", "had", res);

  for (auto const& r : res)
    cout << r << " " << endl;

  return 0;
}


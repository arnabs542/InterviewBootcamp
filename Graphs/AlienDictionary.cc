/*
Comments :
Given a sorted dictionary of alien language, find the order of character
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>

using namespace std;

unordered_map<char, vector<char> > g;

void topologicalSort(char ch, set<char>& visited, stack<char>& s) {
  if (visited.find(ch) != visited.end())
    return;

  visited.emplace(ch);

  cout << "topological sort: " << ch << endl;

  for (auto const& n : g[ch]) {
    topologicalSort(n, visited, s);
  }
  s.push(ch);
}

int firstDiff(const string& s1, const string& s2)
{
  int i = 0;
  int pos = -1;
  
  while (i < s1.size() && i < s2.size() && s1[i] == s2[i])
    ++i;

  if ( i != s1.size() && i != s2.size())
    pos = i;

  return pos;
}

void printGraph()
{
  cout << "graph is: " << endl;

  for (auto const& n: g)
  {
    cout << n.first << "->";
    for (auto const &v : n.second)
      cout <<  v ;
    cout << endl;
  }
}

string findOrder(const vector<string>& strDict)
{
  // construct graph
  for (int i = 0; i < strDict.size()-1; ++i) {
    int pos = firstDiff(strDict[i], strDict[i+1]);
    if (pos != -1) {
      const char ch1 = strDict[i][pos];
      char ch2 = strDict[i+1][pos];
      //cout << strDict[i] << " " << strDict[i+1] << " " << ch1 << " " << ch2 << endl;
      g[ch1].push_back(ch2);
      //printGraph();
    }
  }

  stack<char> s;
  set<char>   visited;

  for (auto const& node : g ) {
    topologicalSort(node.first, visited, s);
  }

  string res;
  while (!s.empty()) {
    res.push_back(s.top());
    s.pop();
  }
  return res;
}

int main(int argc, char** argv)
{
  vector<string> dict = {"baa", "abcd", "abca", "cab", "cad"};
  cout << findOrder(dict) << endl;
  return 0;
}


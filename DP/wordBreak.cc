/*
Comments :
Given an input string and a dictionary of words, segement the input string into
a space separated sequence of dictionary words if possible.
For example, if the input string is "applepie" and the dictionary contains the
standart words of english dictionary, then we would return the string "apple
pie" 
If there are multiple arrangements possible, generate all of them */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isDictWord(const string& str, const vector<string>& dict)
{
  for (auto const& s: dict)
    if (s==str)
      return true;

  return false;
}

void wordBreakRec(string& strWord, int begin, int curr, vector<int>& indices,
                  const vector<string>& strDict, vector<string>& res)
{
  if (curr == strWord.size())
    return;

  if (isDictWord(strWord.substr(begin, curr-begin+1), strDict))
  {
    indices.push_back(curr);

    if (curr == strWord.size()-1)
    {
      string str;
      int start  = 0;
      for (auto const i : indices) {
        str += strWord.substr(start, i-start+1) + " ";
        start = i + 1;
      }
      res.push_back(str);
    }
    else 
    {
      wordBreakRec(strWord, curr+1, curr+1, indices, strDict, res);
    }
    
    indices.pop_back();
  }

  return wordBreakRec(strWord, begin, curr+1, indices, strDict, res);
}

void dfs(const vector<vector<string> >& table, vector<string>& res, string& str,
         int index)
{
  if (index == 0)
  {
    res.push_back(str);
    return;
  }

  for (auto word : table[index])
  {
    string s = word + " " + str;
    dfs(table, res, s, index - word.size());
  }
}

void wordBreakDP(const string& strWord, const vector<string>& strDict, vector<string>& res)
{
  vector<vector<string> > table(strWord.size() + 1, vector<string>());

  for (int s=0; s < strWord.size(); ++s)
  {
    for (int j=s; j < strWord.size(); ++j)
    {
      string word = strWord.substr(s, j-s+1);
      cout << s << " " << j << " " << word << endl;
      if (isDictWord(word, strDict))
        table[j+1].push_back(word);
    }
  }

  if (table.back().empty())
  {
    cout << "no solution" << endl;
    return;
  }

#if 0
  for (int i = 0; i < table.size(); ++i)
  {
    cout << "index: " << i << " ";
    for (auto s : table[i])
    {
      cout << s << " ";
    }
    cout << endl;
  }

#endif

  string s;  
  dfs(table, res, s, table.size()-1);
}

vector<string> wordBreak(string strWord, const vector<string>& strDict)
{
  vector<string> res;
//  vector<int> indices;
//wordBreakRec(strWord, 0, 0, indices, strDict, res);
  wordBreakDP(strWord, strDict, res);
  return res;
}

int main(int argc, char** argv)
{
#if 0
  for (auto const& s : wordBreak("applepie", {"app", "apple", "let", "pie"}))
    cout << s << endl;
#endif
  for (auto const& s : wordBreak("interviewkickstart", {"a", "e", "i", "int",
                                 "inter", "interview", "kick", "kicker",
                                 "kickstart", "star", "start", "view"}))
    cout << s << endl;

  return 0;
}


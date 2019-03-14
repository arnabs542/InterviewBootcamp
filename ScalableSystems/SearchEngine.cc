/*
Comments :
*/

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

struct DocMetadata
{
  int    docId;
  int    pos;
  int    freq;
  string snippet;
};

typdef unordered_map<string, vector<DocMetadata> > Index;
Index index;

set<DocMetadata> queryIndex(const string& str)
{
  istringstream stream(str);

  string s;
  vector<DocMetadata> docs;

  while (stream >> s)
  {
    if (index.find(s) != index.end())
      for (auto const d : index[s])
        docs.push_back(d);
  }

  return docs;
}

int main(int argc, char** argv)
{
  return 0;
}


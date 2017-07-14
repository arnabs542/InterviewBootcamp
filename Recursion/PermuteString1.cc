/*
comments:
Find permutation of a given string such that it is a dictionary word.
If you find one stop there.
*/

#include <iostream>
#include <string>
#include <set>

using namespace std;

set<string> dictionary;

bool isDictionaryPrefix(const string& prefix)
{
  return dictionaryPrefix.find(str) != dictionaryPrefix.end();
}

bool isDictionaryWord(const string& str)
{
  return dictionary.find(str) != dictionary.end();
}

void PermuteStringRec(string& str, int index)
{
  if (index == str.length() - 2 )
  {
    if (isDictionaryWord(str))
      cout << str << endl;
    return
  }

  for (int i = index+1; i < str.length(); ++i)
  {
    swap(str, index, i);
    if (isDictionaryPrefix(str, i)) {
      PermuteStringRec(str, index+1);
 
    swap(str, index, i);
  }
}

void PermuteString(string& str)
{
  PermuteStringRec(str,0);
}

int main(int argc, char** argv)
{
  PermuteString("atc");
  return 0;
}


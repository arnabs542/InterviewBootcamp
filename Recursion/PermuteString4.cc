/*
Comments :
Variation of the sting permutation problem where print permuations of a given
string with atmost 3 permutations that are dictionary words
*/

#include <iostream>
#include <string>
#include <set>

using namespace std;

set<string> dictionary = {"cab", "bac", "bca", "cba"};
set<string> dictionaryPrefix = {"c", "ca", "cab", "a","b", "ab", "ba", "ac",
  "bc", "cb"};

bool isDictionaryWord(const string& str)
{
  return dictionary.find(str) != dictionary.end();
}

bool isDictionaryPrefix(const string& str, int i)
{
  return dictionaryPrefix.find(str.substr(0, i+1)) != dictionaryPrefix.end();
}

void swap(string& str, int i, int j)
{
  char ch = str[i];
  str[i] = str[j];
  str[j] = ch;
}

void PrintPermutationRec(string& str, int index, int& count)
{
  if (index == str.length() - 1)
  {
    if (isDictionaryWord(str))
    {
      cout << str << endl;
      count += 1;
    }
    return ;
  }

  for (int i = index; i < str.length() && count < 3 ; ++i)
  {
    swap(str, index, i);
    if (isDictionaryPrefix(str, index)) {
      PrintPermutationRec(str, index+1, count);
    }
    swap(str, index, i);
  }

}

int PrintPermutation(string& str)
{
  int count = 0;
  PrintPermutationRec(str, 0, count);
}

int main(int argc, char** argv)
{
  string str = "acb";
  PrintPermutation(str);

  return 0;
}


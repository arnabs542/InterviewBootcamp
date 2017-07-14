/*
Comments :
Variation of the Permute a string problem
Print all permutations of a string where the first 3 letters are consonants
*/

#include <iostream>
#include <string>

using namespace std;

void swap(string& str, int i, int j)
{
  char tmp = str[i];
  str[i] = str[j];
  str[j] = tmp;
}

bool isConsonant(char ch)
{
  char ch1 = tolower(ch);
  return !(ch1 == 'a' || ch1 == 'e' || ch1 == 'i' || ch1 == 'o' || ch1 == 'u');
}

void PrintPermutationsRec(string& str, int i)
{
  if (i == str.length() - 1)
  {
    cout << str << endl;
    return;
  }

  for (int j = i; j < str.length(); ++j)
  {
    if ( (i < 3) && isConsonant(str[j]) || i >= 3)
    {
      swap (str, i, j);
      PrintPermutationsRec(str, i+1);
      swap(str, i, j);
    }
  }
}

void PrintPermutations(string& str)
{
  PrintPermutationsRec(str, 0);
}

int main(int argc, char** argv)
{
  string str = "cdfeai";
  PrintPermutations(str);
  return 0;
}


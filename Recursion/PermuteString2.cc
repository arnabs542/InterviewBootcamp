/*
Comments :
Print all permutations of a given string with alternating vowels and consonants
in the permuted string like (vc)*
*/

#include <iostream>
#include <string>

using namespace std;

bool isVowel(char ch)
{
  char ch1 = tolower(ch);
  return ch1 == 'a' || ch1 == 'e' || ch1 == 'i' || ch1 == 'o' || ch1 == 'u';
}

bool isConsonant(char ch)
{
  return !isVowel(ch);
}

bool isEven(int i)
{
  return i % 2 == 0;
}

bool isOdd(int i)
{
  return !isEven(i);
}

void swap(string& str, int i, int j)
{
  char tmp = str[i];
  str[i] = str[j];
  str[j] = tmp;
}

void PrintPermutationsRec(string& str, int  i)
{
  if (i == str.length() - 1) {
    cout << str << endl;
    return;
  }

  for (int j = i; j < str.length(); ++j) {
    if ( (isEven(i) && isVowel(str[j])) || (isOdd(i) && isConsonant(str[j]))) {
      swap(str, i, j);
      PrintPermutationsRec(str, i+1);
      swap(str, i, j);
    }
  }
}

void PrintAlternatePermutations(string& str)
{
  PrintPermutationsRec(str, 0);
}

int main(int argc, char** argv)
{
  string str = "xcdaei";
  PrintAlternatePermutations(str);
  return 0;
}


/*
Comments :
What's a neuronym ?
L10n is a neuronym of the word Localization, where 10 stands for the number of
letters between the first 'L' and the last 'n' in the word.
Generate all such possible neuronyms for any given string (character array) for
e.g nailed
n4d
n3ed na3d
n2led na2ed nai2d

Print progressively longer strings, until there is a 2 in the permutation.

Solution summary:
We need two loops : first is for the size of the sustring that will be replaced
with a digit. This 
*/

#include <iostream>
#include <string>

using namespace std;

void generateNeuronyms(const string& inputStr)
{
  int strLen = inputStr.size();

  for (int n = strLen-2; n >= 2; --n)
  {
    for (int i=1; i <= strLen-1-n; ++i)
    {
      string s = inputStr.substr(0, i) + to_string(n) +
          inputStr.substr(i+n,strLen-i-n);
      cout << s << " ";
    }
    cout << endl;
  }
}


int main(int argc, char** argv)
{
  generateNeuronyms("nailed");
  return 0;
}


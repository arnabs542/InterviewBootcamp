/*
Comments :
*/

#include <iostream>
#include <string>

using namespace std;

void rotate(string& str)
{
  char last = str.back();

  for (int i = str.size()-2; i >= 0; --i)
    str[i+1] = str[i];
  str[0] = last;
}


bool isPalindrome(const string& str)
{
  int begin=0, end = str.size()-1;

  while (begin < end)
  {
    if (str[begin++] != str[end--])
      return false;
  }

  return true;
}


bool isRotationOfPalindrome(string& str)
{
  for (int i = 0; i < str.size(); ++i)
  {
    rotate(str);
    if (isPalindrome(str))
      return true;
  }
  return false;
}
 
int main(int argc, char** argv)
{
  string str("hjijhgi");
  cout << isRotationOfPalindrome(str) << endl;
  return 0;
}


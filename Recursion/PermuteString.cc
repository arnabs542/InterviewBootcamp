#include <iostream>
#include <string>

using namespace std;

void swap(string& str, int i, int j)
{
  char tmp = str[i];
  str[i] = str[j];
  str[j] = tmp;
}

int permuteString(string& str, int index)
{
  if (index == str.length()-1)
    cout << str << endl;

  for (int i = index; i < str.length(); ++i)
  {
    swap(str, index, i);
    permuteString(str, index+1);
    swap(str, index, i);
  }
}

int permuteStringWrapper(string& str)
{
  return permuteString(str, 0);
}

int main(int argc, char** argv)
{
  string str = "ab";
  permuteStringWrapper(str);
  return 0;
}


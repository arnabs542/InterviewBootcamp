#include <iostream>
#include <string>

using namespace std;

void swap(string& str, int i, int j)
{
  char tmp = str[i];
  str[i] = str[j];
  str[j] = tmp;
}

void permuteWithDup(string& str, int index)
{
  if (index == str.size())
  {
    cout << str << endl;
    return;
  }

  for (int i = index; i < str.size(); ++i)
  {
    if ((i != index) && (str[index] == str[i]))
      continue;

    swap(str, index, i);

    permuteWithDup(str, index+1);

    swap(str, index, i);
  }
}


int main(int arc, char** argv)
{
  string str(argv[1]);

  permuteWithDup(str, 0);
  
  return 0;
}


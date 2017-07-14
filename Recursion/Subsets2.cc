/*
Comments :
#Variation : generate all subsets of a set such that the set size is 3
*/

#include <iostream>
#include <string>

using namespace std;

void PrintSubsetsRec(string& str, int index, string& res, int r_index)
{
  if (r_index == 3 || index == str.length()) {
    if (r_index == 3) {
      for (int i = 0; i < r_index; ++i)
        cout << res[i];
      cout << endl;
    }
    return;
  }

  PrintSubsetsRec(str, index+1, res, r_index);
  res[r_index] = str[index];
  PrintSubsetsRec(str, index+1, res, r_index+1);
}

void PrintSubsets(string& str)
{
  string res(str);
  PrintSubsetsRec(str, 0, res, 0);
}

int main(int argc, char** argv)
{
  string str = "acbd";
  PrintSubsets(str);
  return 0;
}


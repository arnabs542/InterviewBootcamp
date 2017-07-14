#include <iostream>
#include <string>

using namespace std;


void PrintSubsetsRec(const string& str, int index, string& res, int r_index)
{
  if (index == str.length()) {
    if (r_index == 0) {
      cout << "empty" << endl; }
    else {
      for (int i = 0; i < r_index; ++i)
        cout << res[i];
      cout << endl;
    }
    return;
  }

  res[r_index] = str[index];
  PrintSubsetsRec(str, index+1, res, r_index+1);
  PrintSubsetsRec(str, index+1, res, r_index); 
}


void PrintSubsets(const string& str)
{
  string res(str);
  PrintSubsetsRec(str, 0, res, 0);
}

int main(int argc, char** argv)
{
  PrintSubsets("ab");
  return 0;
}


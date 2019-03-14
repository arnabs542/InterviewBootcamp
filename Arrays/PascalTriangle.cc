/*
Comments :
*/

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void printPascal(int n)
{
  vector<int> prevRow(n, 0);
  vector<int> currRow(n, 0);

  if (n == 1) {
    cout << 1 << endl;
    return;
  }

  cout << 1 << endl;
  prevRow[0]=1;;
  for (int row=2; row <= n; ++row)  //row
  {
    for (int col = 0; col < row; ++col)
    {
      int v = 0;
      v += (col-1 >= 0) ? prevRow[col-1] : 0;
      v += (col < prevRow.size()) ? prevRow[col] : 0;
      cout << v << " ";
      currRow[col] = v;
    }
    cout << endl;
    prevRow = currRow;
  }
}


int main(int argc, char** argv)
{
  printPascal(atoi(argv[1]));
  return 0;
}


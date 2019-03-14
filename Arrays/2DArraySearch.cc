/*
Comments :
*/

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> Pos;

Pos stepWiseLinearSearch(vector<vector<int> >& array, int target)
{
  int R = array.size();
  int C = array[0].size();
  int i = 0, j = C-1;

  while (i < R && j >=0 )
  {
    if ( target == array[i][j])
      return Pos(i,j);

    if (target > array[i][j])
    {
      ++i;
    }
    else
    {
      --j;
    }
  }

  return Pos(-1,-1);
}

int main(int argc, char** argv)
{
  vector<vector<int> > array = {{1,2,3}, {4,5,6}, {7,8,9}};
  Pos pos = stepWiseLinearSearch(array,5);
  cout << pos.first << "," << pos.second << endl;

  return 0;
}


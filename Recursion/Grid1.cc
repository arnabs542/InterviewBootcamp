/*
   Variation 1 on the grid problem (count all paths from the top left cell to
   the bottom right cell)
   In this assume some cells are not allowed (they are marked with a star (*))
*/

#include <iostream>
#include <vector>

using namespace std;

static const vector<vector<char> > grid = {{1,'*'}, {2,2}};
static const int ROWS = grid.size();
static const int COLS = grid[0].size();


int CountAllPathsRec(int row, int col)
{
  if (row == ROWS-1 || col == COLS-1)
    return 1;


  int countRow = 0;
  int countCol = 0;
  if (grid[row+1][col] != '*')
    countRow = CountAllPathsRec(row+1, col);
  if (grid[row][col+1] != '*')
    countCol =CountAllPathsRec(row, col+1);

  return countRow + countCol;
}

int CountAllPaths()
{
  return CountAllPathsRec(0, 0);
}

int main(int argc, char** argv)
{
  cout << CountAllPaths() << endl;
  return 0;

}


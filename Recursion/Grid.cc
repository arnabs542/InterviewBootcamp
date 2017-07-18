/*
   count all paths from the top left cell to the bottom right cell
*/

#include <iostream>
#include <vector>

using namespace std;

static const vector<vector<char> > grid = {{1,1,1,1}, {2,2,2,2}, {3,3,3,3}, {4,4,4,4} };
static const int ROWS = grid.size();
static const int COLS = grid[0].size();


int CountAllPathsRec(int row, int col)
{
  if (row == ROWS-1 || col == COLS-1)
    return 1;

  return CountAllPathsRec(row+1, col) + CountAllPathsRec(row, col+1);
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


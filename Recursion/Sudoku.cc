/*
Comments :
Given a 9x9 sudoku partially filled matrix. Solve it and print one solution
otherwise say "no solution"
*/

#include <iostream>
#include <set>
#include <vector>

using namespace std;

#define MAX_ROW 9
#define MAX_COL 9

typedef vector<vector<int> > Matrix;

bool noConflict(const Matrix& m, int row, int col)
{
  set<int> setValues;
  // check all elements in row
  for (int  c = 0; c < MAX_COL; ++c)
    if (m[row][c] != -1 && !setValues.insert(m[row][c]).second)
      return false;

  setValues.clear();
  // check all elements in column
  for (int r=0; r < MAX_ROW; ++r)
    if(m[r][col] != -1 && !setValues.insert(m[r][col]).second)
       return false;

  setValues.clear();
  // check all elements in 3x3 matrix
  int beginRow = (row/3) * 3;
  int beginCol = (col/3) * 3;
  for (int i = beginRow; i < beginRow+3; ++i)
    for (int j = beginCol; j < beginCol+3; ++j)
      if (m[i][j] != -1 && !setValues.insert(m[i][j]).second)
        return false;

  return true;
}

void printMatrix(const Matrix& m)
{
  cout << "solution : " << endl;

  for (int i = 0; i < MAX_ROW; ++i)
  {
    for (int j = 0; j < MAX_COL; ++j)
    {
      cout << m[i][j] << " ";
    }
    cout << endl;
  }
}

void sudoku(Matrix& m, int row, int col, int& count)
{
  if (row == MAX_ROW) {
    printMatrix(m);
    count += 1;
    return;
  }

  int j = col;
  while (j < MAX_COL && m[row][j] != -1) j++;

  if (j == MAX_COL) return sudoku(m, row+1, 0, count);

  for (int n = 1; n <= 9; ++n) {
    //printf("%d\n", m[row][j]);
    m[row][j] = n;

    if (noConflict(m, row, j))
    {
      if (j < MAX_COL) sudoku(m, row, j+1, count); 
      else sudoku(m, row+1, 0, count);
    }

    m[row][j] = -1;
  }
}

int main(int argc, char** argv)
{
  Matrix m(MAX_ROW, vector<int>(MAX_COL, -1));
  m = {{ 9, -1, 6, -1,  7, -1,  4, -1,  3},
       {-1, -1,-1,  4, -1, -1,  2, -1, -1},
       {-1,  7,-1, -1,  2,  3, -1,  1, -1},
       { 5, -1,-1, -1, -1, -1,  1, -1, -1},
       {-1,  4,-1,  2, -1,  8, -1,  6, -1},
       {-1, -1, 3, -1, -1, -1, -1, -1,  5},
       {-1,  3,-1,  7, -1, -1, -1, 5,  -1},
       {-1, -1, 7, -1, -1,  5, -1, -1, -1},
       { 4, -1, 5, -1,  1, -1,  7, -1,  8}
  };
  int count = 0;
  sudoku(m, 0, 0, count);
  if (count == 0)
    cout << "no solution" << endl;

  return 0;
}


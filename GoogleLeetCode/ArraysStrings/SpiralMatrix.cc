#include <vector>
#include <iostream>

using namespace std;

vector<int> spiralOrder(vector<vector<int> >& matrix)
{
  vector<int> res;
  if (matrix.empty())
    return res;

  int minRow = 0, maxRow = matrix.size()-1;
  int minCol = 0, maxCol = matrix[0].size()-1;

  while (minRow <= maxRow && minCol <= maxCol)
  {
    int currRow = minRow;
    int currCol = minCol;

    //print top row
    for (; currCol <= maxCol; ++currCol)
      res.push_back(matrix[currRow][currCol]);

    ++minRow;
    currCol = maxCol;
    currRow = minRow;
    
    //print rightmost col
    bool done = false;
    for (; minCol  <= maxCol && currRow <= maxRow; ++currRow) {
      done = true;
      res.push_back(matrix[currRow][currCol]);

    }

    if (done)
      --maxCol;
    currRow = maxRow;
    currCol = maxCol;

    done = false;
    //print bottom row
    for (; minRow <= maxRow && currCol >= minCol; --currCol) {
      done = true;
      res.push_back(matrix[currRow][currCol]);
    }

    if (done)
      --maxRow;
    
    currRow = maxRow;
    currCol = minCol;
    done = false;
    //print leftmost col
    for (; minCol <= maxCol && currRow >= minRow; --currRow) {
      res.push_back(matrix[currRow][currCol]);
      done = true;
    }
    if (done)
      ++minCol;
      
  }

  for (auto r: res)
    cout << r << ",";
  cout << endl;

  return res;
}



int main()
{
  vector<int> res1 = {1,2,3};
  vector<vector<int> > matrix = {{1,2,3}};
  assert(spiralOrder(matrix) == res1);

  vector<vector<int> > matrix2 = {{1},{2}, {3}};
  assert(spiralOrder(matrix) == res1);

  return 0;
}

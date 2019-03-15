#include <iostream>
#include <vector>
#include <utility>
#include <cassert>

using std::cout;
using std::endl;
using std::vector;
using std::pair;


bool find(vector<vector<int> >& matrix, int value, pair<int, int>& pos)
{
  int max_rows = matrix.size() - 1;
  int max_cols = matrix[0].size() - 1;

  int curr_row = 0, curr_col = max_cols;

  while (curr_col >= 0 && curr_row >=0 && curr_row <= max_rows)
  {
    if (matrix[curr_row][curr_col] == value) {
      pos = {curr_row, curr_col};
      return true;
    }
    if (matrix[curr_row][curr_col] < value)
      ++curr_row;
    else
      --curr_col;
  }

  return false;
}


int main()
{
  vector<vector<int> > matrix = { {7,12,18,25,31},
                                  {10,15,20,27,32},
                                  {13,19,22,29,33},
                                  {17,26,29,33,36}
                                };

  pair<int, int> pos;
  assert(find(matrix, 12, pos) == true );
  cout << pos.first << "," << pos.second << endl;

  assert(find(matrix, 26, pos) == true );
  cout << pos.first << "," << pos.second << endl;
  
  assert(find(matrix, 14, pos) == false );
  cout << pos.first << "," << pos.second << endl;
  
  return 0;
}



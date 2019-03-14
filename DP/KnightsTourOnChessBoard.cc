/*
Comments :
*/

#include <iostream>

using namespace std;


vector<pair<int, int> > positions(int r, int c, int max_row, int max_col)
{
  static vector<pair<int, int> > moves = {{2,1}, {2,-1}, {1,2}, {-1,2}, {-1,-2}, {1,-2}, {-2,1}, {-2,-1}};

  vector<pair<int, int> > pos;
  for (auto mv : moves)
  {
    int next_r = mv.first + r;
    int next_c = mv.second + c;

    if (next_r >= 0 && next_r <= max_row && next_c >=0 && next_c <= max_col)
      pos.push_back(make_pair(next_r, next_c));
  }

  return pos;
}

int find_minimum_number_of_moves(int rows, int cols, int start_row, int start_col, int end_row, int end_col) {
    // Write your code here.

    vector<vector<int> > board(rows+1, vector<int>(cols+1,
                                                 numeric_limits<int>::max()));
    board[start_row][start_col] = 0;

  for (int r=start_row; r <= rows; ++r)
  {
    for (int c = start_col; c <= cols; ++c)
    {
      if (board[r][c] == numeric_limits<int>::max()) 
          continue;
      for (auto pos : positions(r, c, rows, cols))
        board[pos.first][pos.second] = min(board[pos.first][pos.second], board[r][c] + 1);
    }
  }

  return (board[end_row][end_col] == numeric_limits<int>::max()) ? -1 : board[end_row][end_col];

}

Failing Test cases
2
7
0
5
0
1

expected : 2

3
8
0
6
1
3

expected 2

3
8
0
6
2
0
expected 4


3
33332
1
1599
1
0

expected 801


4
24975
3
21841
1
13

expected 10914

10000
10
9876
8
1234
2

expected 4322

10
9999
0
0
9
9988

expected 4995

20
5000
0
4325
0
3

expected 2162

20
5000
0
4325
0
3

expected 11


315
316
222
123
123
222

expected 66

315
315
0
314
314
0

expected 210

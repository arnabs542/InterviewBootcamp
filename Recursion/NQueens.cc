/*
Comments :
Solve the N- queens problem recursively.
Problem statement: Place N queens on an NxN chessboard, such that no two queens
are in the line of attach (horizontally, vertically, diagonally)

Input : N
Output: all possible arrangements of N queens on the board  
*/

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> Position;
typedef vector<pair<int, int> > Positions;

bool noConflict(const Position& pos, const Positions& positions)
{
  int x = pos.first; int y = pos.second;

  for ( auto p : positions) {
    int x1 = p.first; int y1 = p.second;
    if (x == x1 || y == y1 || abs(x-x1) == abs(y-y1))
      return false;
  }

  return true;
}

void printVector(const vector<vector<char > >& board)
{
  for (int i = 0; i < board.size(); ++i)
  {
    for (int j = 0; j < board[0].size(); ++j)
    {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
}

void printArrangement(int N, const Positions& positions)
{
  vector<vector<char > > board(N, vector<char>(N, '0'));


  for (auto p : positions) {
    int i = p.first; int j = p.second;
    board[i][j] = '*';
  }

  cout << "----Arrangement---" << endl;
  printVector(board);
}

void PrintNQueensRec(int N, int n, int q, Positions& positions)
{
  if (q == 0)
  {
    printArrangement(N, positions);
    return;
  }

  for (int j = 0; j < N; ++j)
  {
    if (noConflict(Position(n, j), positions)) {
      positions.push_back(Position(n,j));
      PrintNQueensRec(N, n+1, q-1, positions);
      positions.pop_back();
    }
  }
}


void PrintNQueens(int N)
{
  Positions positions;
  PrintNQueensRec(N, 0, N, positions); 
}

int main(int argc, char** argv)
{
  int N = atoi(argv[1]);
  PrintNQueens(N);
  return 0;
}


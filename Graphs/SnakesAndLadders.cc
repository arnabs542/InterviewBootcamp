/*
Comments :
Given a snake and ladder rectangular MxN board game, find the minimum number of
dice throws required to reach the final cell from the first cell

Solution Summary : Can encode the board as a vector with MxN cells. The value of
each cell is the value of the next cell (lower one in case of snake) and (higher
in case of ladder), same in case of normal cell.
Need not maintain a visited set since we can visit the same cell again if we
encounter a snake for example. A BFS should return the shortest number of moves.
*/

#include <iostream>
#include <queue>
#include <utility>
#include <map>

using namespace std;

vector<int> board = {1, 15, 3, 4, 7, 6, 7, 8, 27, 10, 11, 12, 13, 14, 15, 16, 4,
29, 19, 6, 21, 22, 23, 24, 35, 26, 27, 28, 29, 30, 31, 30, 33, 12, 35, 36};

int moves()
{
  int totalMoves = -1;
  map<int, int> m;

  queue<pair<int, int> > q;
  q.push(make_pair(board[0], 0));
  m[board[0]] = 0;

  while (!q.empty())
  {
    int pos = q.front().first;
    int moves = q.front().second;
    q.pop();

    if (pos == board.size()) {
      totalMoves = moves;
      break;
    }

    for (int i = 1; i <=6; ++i)
    {
      int p = pos + i;
      if (p <= board.size()) {
        q.push(make_pair(board[p-1], moves+1));
        m[board[p-1]] = i;
      }
    }
  }

  return totalMoves;
}

int main(int argc, char** argv)
{
  cout << moves() << endl;
  return 0;
}


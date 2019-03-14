/*
Comments :
Assume that you are given a normal chessboard and a knight that moves like in
normal chess . You are then given two inputs: starting location and ending
location in the form of x,y coordinates. The goal is to calculate the shortest
number of moves that the knight can take to get to the target location.
*/

#include <iostream>
#include <utility>
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <limits>

using namespace std;

typedef pair<int, int> Position;

static const vector<Position> Moves = {{-1,-2}, {-2, -1}, {-2, 1}, {-1,2}, {1,2}, {2,1}, {2,-1}, {1,-2}};

Position operator+(const Position& p1, const Position& p2){
    return Position(p1.first+p2.first, p1.second+p2.second);
}

void getNeighbors(const Position& pos, int rows, int cols, vector<Position>& n)
{
  for (const auto m : Moves) {
      Position p = pos + m;
      if (p.first >= 0 && p.first < rows && p.second >=0 && p.second < cols)
          n.push_back(p);
  }

}

int minimumMoves(int rows, int cols, int startx, int starty, int endx, int endy)
{

  queue<pair<Position, int> > q;
  set<Position> visited;
  Position end(endy, endx);

  int count = -1;

  q.push(make_pair(Position(starty, startx), 0));

  while (!q.empty())
  {
    Position p = q.front().first;
    int moves  = q.front().second;
    q.pop();

    if (p == end) {
      count = moves;
      break;
    }
      
    visited.insert(p);

    vector<Position> n;
    getNeighbors(p, rows, cols, n);
      
    for (auto const& pos : n) {
      if (visited.find(pos) == visited.end())
        q.push(make_pair(pos, moves+1));
    }
  }

  return count;
}

int minimumMovesDjk(int rows, int cols, int startx, int starty, int endx, int
                    endy)
{
  priority_queue<pair<int, Position> > pq;
  vector<vector<int> > board(rows, vector<int>(cols, numeric_limits<int>::max()));
  
  pq.push(make_pair(0, Position(starty, startx)));

  while (!pq.empty())
  {
    Position p = pq.top().second;
    int r = p.first; int c = p.second;

    int len = pq.top().first;
    pq.pop();
    vector<Position> n;
    getNeighbors(p, rows, cols, n);

    for (auto const& pos : n)
    {
      if (board[pos.first][pos.second] > len + 1)
      {
        board[pos.first][pos.second] = len+1;
        pq.push(make_pair(len+1, pos));
      }
    }
  }

  return board[endy][endx];
}


int main()
{
  cout << minimumMovesDjk(8, 8, 0, 0, 7, 7) << endl;
  return 0;
}


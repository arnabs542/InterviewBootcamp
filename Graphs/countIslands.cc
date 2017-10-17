/*
Comments :
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<int > > Matrix;
typedef pair<int, int> Pos;

vector<Pos> Neigh = {{-1,-1}, {-1,0}, {-1, 1}, {0,-1}, {0, 1}, {1, -1}, {1,0},
  {1,1}};



vector<Pos> getNeighbors(int i, int j, const Matrix& matrix)
{
  vector<Pos> neighs;
  int M = matrix.size();
  int N = matrix[0].size();

  for (auto const& n : Neigh)
  {
    int r = i + n.first;
    int c = j + n.second;

    if (r >= 0 && r < M && c >=0 && c < N)
      neighs.push_back(Pos(r,c));
  }

  return neighs;
}

int countIslandsHelper(Matrix& matrix, int i, int j)
{
  if (!matrix[i][j])  // not land
    return 0;

  matrix[i][j] = 0; // visited

  for (const auto& n : getNeighbors(i, j, matrix))
  {
    countIslandsHelper(matrix, n.first, n.second);
  }

  return 1;
}

int countIslands(Matrix& matrix)
{
  int count = 0;

  for (int i=0; i < matrix.size(); ++i)
  {
    for (int j=0; j < matrix[0].size(); ++j)
    {
      count += countIslandsHelper(matrix, i, j);
    }
  }

  return count;
}

int main(int argc, char** argv)
{
  return 0;
}


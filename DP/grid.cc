/*
Comments :
given a grid with values in each grid node representing the cost of the path.
Then find the maxCost path from (0,0) to (M-1, N-1)
Time Complexity : O(2^ (M+N-2)), with memorization : O(M x N)
Space Complexity : O(M+N)
*/

#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int> > Grid;
Grid g;


int highestValuePath(int i, int j)
{
  int M = g.size() - 1;
  int N = g[0].size() - 1;

  if (i == M && j == N)
    return grid[i][j];

  if (i == M || j == N) 
  {
    if (i == M)
      return grid[i][j] + highestValuePath(i, j+1);
    else
      return grid[i][j] + highestValuePath(i+1, j);
  }

  return grid[i][j] + max(highestValuePath(i+1, j), highestValuePath(i, j+1));
}

int highestValuePath(Grid& g)
{

  vector<vector<int> > cache(M, vector<N, 0> );

  for (int i = M; i >=0; --i)
  {
    for (int j = N; j >=0; --j)
    {
      if (i == M && j == N)
        cache[i][j] = grid[i][j];
      else if (i == M)
        cache[i][j] = grid[i][j] + cache[i][j+1];
      else if (j == N)
        cache[i][j] = grid[i][j] + cache[i+1][j];
      else
        cache[i][j] = g[i][j] + max(grid[i+1][j], grid[i][j+1]);
    }
  }

  return cache[0][0];
}


int main(int argc, char** argv)
{
  cout << highestValuePath(grid, 0, 0) << endl;
  return 0;
}


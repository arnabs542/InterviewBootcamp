/*
Comments :
*/

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<pair<int,int> > neighbors = {{0,1}, {1,0}};

vector<pair<int, int> >  getNextPos(int i, int j, const vector<vector<int> >&
                                    array)
{
  int MaxRow = array.size();
  int MaxCol = array[0].size();
  vector<pair<int, int> > nextPos;

  for (auto const n : neighbors) 
  {
    int row = i + n.first;
    int col = j + n.second;
    if (row >= 0 && row < MaxRow && col >=0 && col < MaxCol && array[row][col])
      nextPos.push_back(make_pair(row, col));
  }

  return nextPos;

}

int numOfPathsRec(const vector<vector<int> >& array, int row, int col,
                  vector<vector<int> >& table)
{
  int MaxRow = array.size();
  int MaxCol = array[0].size();

  if (table[row][col] != -1)
    return table[row][col];

  if (row == MaxRow-1 || col == MaxCol-1)
    return table[row][col] = 1;

  int count = 0;
  vector<pair<int, int> > nextPos = getNextPos(row, col, array);

  for (auto const& pos : nextPos)
    count += numOfPathsRec(array, pos.first, pos.second, table);

  return table[row][col] = count;
}

int numPathsDP(const vector<vector<int> >& array)
{
  vector<vector<int > > dpTable(array.size(), vector<int>(array[0].size(), 0));

  int MaxRow = array.size() - 1;
  int MaxCol = array[0].size() - 1;

  if (array[MaxRow-1][MaxCol-1])
    dpTable[MaxRow-1][MaxCol-1] = 1;
  else 
    return 0;

  for (int i = M-1; i >= 0; --i)
  {
    for (int j = N-1; j >=0; --j)
    {
      if (i == M-1 && j==N-1)
        continue;
      if (!array[i][j]) {
        dpTable[i][j] = 0;
      } else {
        int sum = 0;
        if (i < M-1)
          sum += dpTable[i+1][j];
        if (j < N-1)
          sum += dpTable[i][j+1];
        dp[i][j] = sum;
      }
    }
  }

  return dpTable[0][0];
}

int numOfPaths(const vector<vector<int> >& array)
{
  vector<vector<int> > table(array.size(), vector<int>(array[0].size(), -1));
  return numOfPathsRec(array, 0, 0, table);
}

int main(int argc, char** argv)
{
  vector<vector<int> > array = {{1,1}, {0,1}}; 
  cout << numOfPaths(array) << endl;
  return 0;
}


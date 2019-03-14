/*
Comments :
*/

#include <iostream>
#include <vector>

using namespace std;

int maxWinRec(const vector<int>& coins, int beginIndex, int endIndex,
              vector<vector<int> >& table)
{

  if (beginIndex > endIndex)
    return 0;

  if (table[beginIndex][endIndex] != -1)
    return table[beginIndex][endIndex];

  int maxCoins = max( coins[beginIndex] + min(maxWinRec(coins, beginIndex+2, endIndex, table),
                                              maxWinRec(coins, beginIndex+1, endIndex-1,table)),
                      coins[endIndex]   + min(maxWinRec(coins, beginIndex+1, endIndex-1, table),
                                              maxWinRec(coins, beginIndex, endIndex-2, table)));

  return table[beginIndex][endIndex] = maxCoins;
}

int maxWin(vector<int> coins)
{
  vector<vector<int> > table(coins.size(), vector<int>(coins.size(), -1));
  maxWinRec(coins, 0, coins.size()-1, table);
  return table[0][coins.size()-1];
}

int main(int argc, char** argv)
{
  return 0;
}


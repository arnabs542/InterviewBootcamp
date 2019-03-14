/*
Comments :
*/

#include <iostream>
#include <vector>

using namespace std;

int numWays(const vector<int>& numSteps, int numStairs, int currStair)
{
  if (currStair == numStairs)
    return 1;

  int count = 0;
  int maxStepSize = numStairs-currStair;

  for (auto step : numSteps)
    if (step <= maxStepSize)
      count += numWays(numSteps, numStairs, currStair+ step);

  return count;
}

int numWaysMemoized(const vector<int>& numSteps, int numStairs, int currStair,
                    vector<int>& table)
{
  if (table[currStair] != -1)
    return table[currStair];

  if (currStair == numStairs)
    return table[currStair] = 1;

  int count = 0;
  int maxStepSize = numStairs-currStair;

  for (auto step : numSteps)
    if (step <= maxStepSize)
      count += numWays(numSteps, numStairs, currStair + step);

  return table[currStair] = count;
}

int numWaysDP(const vector<int>& numSteps, int numStairs)
{
  vector<int> dpTable(numStairs+1, 0);
  dpTable[0] = 1;

  for (int stair=1; stair <= numStairs; ++stair)
  {
    for (auto step : numSteps)
      if (stair - step >= 0)
        dpTable[stair] += dpTable[stair - step];
  }

  return dpTable[numStairs];
}

int numWaysToClimb(const vector<int>& numSteps, int numStairs)
{
  return numWaysDP(numSteps, numStairs);
  //vector<int> table(numStairs+2, -1);
  //return numWaysMemoized(numSteps, numStairs, 0, table);
  //return numWays(numSteps, numStairs, 0);
}

int main(int argc, char** argv)
{
  cout << numWaysToClimb({1,2}, 10) << endl;
  return 0;
}


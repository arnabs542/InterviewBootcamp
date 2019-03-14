/*
Comments :
In American football a team can get {2,3,7} points. If a team gets P points how
many ways can a team get P points, given than order is important.
*/

#include <iostream>
#include <vector>

using namespace std;

int numWays(int score, const vector<int>& possibleScores)
{
  if (score == 0) 
    return 1;

  int count = 0;
  for (auto const s : possibleScores)
    if (s <= score)
      count += numWays(score-s, possibleScores);

  return count;
}

// Order is important
int numWaysDP(int score, const vector<int>& possibleScores)
{
  vector<int> dpTable(score+1, 0);
  dpTable[0] = 1;

  for (int s=1; s <= score; ++s)
  {
    int count  = 0;
    for (auto const ps : possibleScores)
    {
      if (ps <= s)
        count += dpTable[s-ps];
    }
    dpTable[s] = count;
  }

  return dpTable[score];
}

// Order is not important
int numWaysDPIgnoreOrder(int score, const vector<int>& possibleScores)
{
  vector<vector<int> > dpTable(score+1, vector<int>(possibleScores.size(), 0));

  for (int j = 0; j < possibleScores.size() ; ++j)
    dpTable[0][j] = 1;

  for (int s = 1; s <= score; ++s)
  {
    int sum = 0;

    for (int prev = 0; prev < possibleScores.size(); ++prev)
    {
      int sum  = 0;
      for (auto const ps : possibleScores)
      {
        if (ps <= s && prev < ps)
          sum += dpTable[s-ps][prev];
      }
      dpTable[s][prev] = sum;
    }
  }

  return dpTable[score][possibleScores[0]];
}

int main(int argc, char** argv)
{
  cout << numWaysDP(4, {1,3,7}) << endl;
  cout << numWaysDPIgnoreOrder(4, {1,3,7}) << endl;
  return 0;
}


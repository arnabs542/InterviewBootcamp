/*
Comments :
given an array of numbers (there can be repetitions), find if it can be divided into two
groups that have the same sum

Time complexity of this algorithm is pseudo polynomial, because it depends on
the size of input T= sum of array/2 and complexity = O(n*T). So it is not
polynomial. If we increase each element of the array by 10 the solution
complexity becomes 10 times
*/

#include <iostream>

using namespace std;

bool isTiePossible(const vector<int>& a)
{
  int n = a.length();
  int sum = 0;

  for (int i=0; i < n; ++i)
    sum += a[i];

  if (sum %2 == 1) 
    return false;

  int T = sum/2;

  vector<vector<int> > dp(n+1, vector<int>(T+1, 0));

  for (int i = 0; i < n; ++i)
    dp[i][0] = 1;

  for (int t = 1; t <= T; ++t)
    dp[n][t] = 0;

  for (int i = n-1; i >= 2; --i)
  {
    for (int t = 1; t <= T; ++t)
    {
      dp[i][t] = dp[i+1][t] || t > a[i] && dp[i+1][t-a[i]];
    }
  }
  return dp[0][T];
}


int main(int argc, char** argv)
{
  return 0;
}


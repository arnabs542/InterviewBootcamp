/*
Comments :
Try to print the actual sequence
*/

#include <iostream>
#include <vector>

using namespace std;

int longestIncSubsequence(const vector<int>& array)
{
  int n = array.size();

  vector<vector<int> > dp(array.size()+1, array[0].size()+1);

  for (int i = n-1; i >= 0; --i)
  {
    for (int p = 0; p <= i; ++p)
    {
      dp[i][p] = dp[i+1][p];
      if (p==0 || a[i] > a[p])
        dp[i][p] = max(dp[i][p], dp[i+1][i+1] + 1);
    }
  }

  return dp[0][0];

}

int main(int argc, char** argv)
{
  return 0;
}


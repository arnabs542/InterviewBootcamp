#include <vector>
#include <string>
#include <iostream>

using namespace std;

int countSteps(int nSteps)
{
  vector<int> dp(nSteps+1, 0);
  
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;

  for (int n=3; n <= nSteps; ++n)
  {
    dp[n] = dp[n-1] + dp[n-2] + dp[n-3];
  }

  return dp[nSteps];
}

int main(int argc, char** argv)
{
  cout << countSteps(stoi(argv[1])) << endl;
}

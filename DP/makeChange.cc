/*
Comments :
You are given n types of coin denominations of values v[1] < v[2] < ... < v[n]
(all integers). Give an algorithm which makes change for an amount of money C
with as few coins as possible.
-> Assume there are multiple coins of every denomination
-> Assume v[1]=1 i.e there is always a combination that leads to C
-> There may be multiple ways of reaching C. We want a DP based solution that
leads to the method using least number of coins
-> Input : C and denominations array
-> Output: combination using minumum number of coins(repeat coins are ok)that
leads to C. Print any one

For extra credit: there may be multiple such combinations . Print all such
combinations.
*/

#include <iostream>
#include <vector>
#include <limits>
#include <unordered_map>

using namespace std;


void printAllSolutions(int C, int prev, const vector<vector<int> >& table,
                       vector<int>& solution)
{
  if (C==0)
  {
    for (auto s : solution)
      cout << s << " "; 
    cout << endl;
  }

  for (auto const denom : table[C])
  {
    if (denom <= prev) 
    {
      solution.push_back(denom);
      printAllSolutions(C-denom, denom, table, solution); 
      solution.pop_back();
    }
  }
}

void makeChange(int C, const vector<int>& denominations)
{
  vector<int> table(C+1, 0);
  vector<vector<int> > solution(C+1, vector<int>());
  table[1] = 1;
  solution[1].push_back(1);

  for (int sum=2; sum <= C; ++sum)
  {
    int numCoins = numeric_limits<int>::max();
    unordered_map<int, vector<int> > countToDenomination;

    for (auto const denom : denominations)
      if (denom <= sum) 
      {
        if (numCoins >= table[sum-denom]+1)
        {
          numCoins = 1 + table[sum-denom];
          countToDenomination[numCoins].push_back(denom);
        }
        table[sum]= numCoins;
        solution[sum] = countToDenomination[numCoins];
      }
  }

  vector<int> printSol;
  printAllSolutions(C, C+1, solution, printSol);

#if 0
  int sum = C;
  while(sum) 
  {
    cout << solution[sum] << ",";
    sum -= solution[sum];
  }
  cout << endl;
#endif
}

int main(int argc, char** argv)
{
  makeChange(10, {1,2,3,5,6});
  return 0;
}


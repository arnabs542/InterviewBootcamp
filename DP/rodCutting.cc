/*
Comments :
*/

#include <iostream>
#include <vector>

using namespace std;

int costOfRodCuttingMemoized(int length, vector<int>& price)
{
  vector<int> dpTable(totalLength+1, -1);

  if (length == 0)
    return dpTable[0] = 0;

  if (dpTable[length] != -1)
    return dpTable[length];

  int maxCost = numeric_limits<int>::min();

  for (int c=1; c <= length; ++c)
    maxCost = max(maxCost, price[c] + costOfRodCutting(length-c, price,
                                                     totalLength));

  return dpTable[length] = maxCost;
}

int costOfRodCurringDP(int length, unordered_map<int, int>& price, vector<int>& res)
{
  vector<int> dpTable(totalLength+1, 0);
  vector<int> printTable(totalLength+1, 0);
  dpTable[0] = 0;

  for (int len=1; len <= length, ++len)
  {
    int maxCost = numeric_limits<int>::min();
    int bestCut = numeric_limits<int>::min();
    for (int j = 1; j <= l; ++j)
    {
      if (price[j] + dpTable[len-j] > maxCost) {
        maxCost = price[j] + dpTable[len-j];
        bestCut = c;
      }
    }
    printTable[len] = bestCut;
    dpTable[len] = maxCost;
  }

  for (int l = length; l > 0; l -= printTable[l])
    cout << printTable[l] << " ";
  cout << endl;

  return dpTable[length];
}

int main(int argc, char** argv)
{
  unorderd_map<int, int> priceList;
  cout << costOfRodCuttingMemoized(length, priceList) << endl;
  return 0;
}


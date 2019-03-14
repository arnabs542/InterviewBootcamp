/*
Comments :
Problem statement : there are N houses in a row with some value. A thief is
going to steal the maximum value in these houses with the condition that he
cannot steal in two adjacent houses because the owner will inform his two
adjacent neighbors. What is the maximum stolen value. For example for houses {6,
1,2,7} the maximum stolen value is 13.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxStolenValueRec(const vector<int>& arrHouseValues, int index)
{
  if (index >= arrHouseValues.size())
    return 0;

  int amt1 = arrHouseValues[index] + maxStolenValueRec(arrHouseValues, index+2);
  int amt2 = maxStolenValueRec(arrHouseValues, index+1);

  return max(amt1, amt2);
}

int maxStolenValueDP(const vector<int>& arrHouseValues)
{
  vector<int> dpTable(arrHouseValues.size(), 0);
  dpTable[0] = arrHouseValues[0];

  for (int house = 1; house < arrHouseValues.size(); ++house)
  {
    dpTable[house] = max(arrHouseValues[house] + (house >=2 ? dpTable[house-2] : 0),
                         dpTable[house-1]);
  }

  return dpTable[arrHouseValues.size()-1];
}

int maxStolenValue(const vector<int>& arrHouseValues)
{
  //return maxStolenValueDP(arrHouseValues);
  return maxStolenValueRec(arrHouseValues, 0);
}


int main(int argc, char** argv)
{

  cout << maxStolenValue({6,1,2,7});
  return 0;
}


/*
Comments :
*/

#include <iostream>
#include <vector>
#include <limits>

using namespace std;


//approch 1 : brute force O(n^3)
int findMaxBrute(vector<int> array)
{
  int maxSum = numeric_limits<int>::min();

  for (int b = 0; b < array.size() - 1; ++b)
  {
    for (int e = b+1; e < array.size(); ++e)
    {
      int sum = 0;
      for (int k = b; k <= e; ++k)
        sum += array[k];
      maxSum = max(maxSum, sum);
    }
  }
  return maxSum;
}

//approach 3 : O(n)
int findMax(vector<int> array)
{
  int maxSum = numeric_limits<int>::min();
  int sum  = 0;
  
  for(int k = 0; k < array.size(); ++k)
  {
    if (sum + array[k] > 0)
    {
      sum += array[k];
      maxSum = max(maxSum, sum);
    }
    else 
    {
      sum = 0;
    }
  }

  return maxSum;
}

// approach 4:
// main a cumulative sum array and a mimimum cumulative sum array
// Can be done with O(1) additional space 
int findMaxCumulative(vector<int> array)
{
  int sum = 0;
  vector<int> cumulArray; // maintain a cumulative sum of the elements of array
 
  for (auto const &a : array) {
    sum += a;
    cumulArray.push_back(sum);
  }

  vector<int> minCumSum; // maintain the minimum cumulative sum so far
  int minSoFar = numeric_limits<int>::max();
  for (auto const& c : cumulArray) {
    minSoFar = min(minSoFar, c);
    minCumSum.push_back(minSoFar);
  }

  // the max sum at index i is the difference b/w the cumulative sum till index
  // i and the minimum cumulative sum at index i
  for (int i = 0; i < array.size(); ++i)
    cumulArray[i] -=  minCumSum[i];

  // Now find the max sum from all sums at indices 0 - N-1
  int maxSum = numeric_limits<int>::min();
  for (auto const& c: cumulArray)
    maxSum = max(maxSum, c);

  return maxSum;
}

int main(int argc, char** argv)
{
  vector<int> array = {-1, 10, -5, 2, 7, -8};

  cout << "brute force: " << findMaxBrute(array) << endl;
  cout << "O(n): " << findMax(array) << endl;
  cout << "cumulative : " << findMaxCumulative(array) << endl;
  return 0;
}


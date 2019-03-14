/*
Comments :
*/

#include <iostream>
#include <vector>

using namespace std;

int findMinCoins(vector<int> coins, int K)
{
  if (K == 0) 
    return 0;

  if (K < 0)
    return numeric_limits<int>::max();

  int minCoins = numeric_limits<int>::max();
  for (auto c : coins)
  {
    minCoins = min(minCoins, findMinCoins(coins, K-c));
  }

  return minCoins + 1;
}

typdedef unordered_map<int, int> Cache;

int findMinCoinsMemoization(vector<int>& coins, int K, Cache& cache)
{
  if (cache.find(K) != cache.end())
    return cache[K];

  if (K == 0)
  {
    cache[0] = 0;
    return 0;
  }

  int minCoins = numeric_limits<int>::max();

  for (auto c : coins)
  {
    if (c <= K)
      minCoins = min(minCoins, findMinCoinsDP(K-coins));
  }

  cache[K] = minCoins + 1;
  return cache[K];
}

int findMinCoinsDP(vector<int>& coins, int K)
{
  Cache cache;

  int sum = 0;
  while (sum != K)
  {
    if (sum == 0) {
      cache[0] = 0;
    }
    else {
      int minSum = numeric_limits<int>::max();

      for i(auto c : coins) {
        if (c <= sum)
          minSum = min (cache[sum - c], minSum);
      }
      cache[sum] = minSum + 1;
    }
    ++sum;
  }

  return cache[K];

}

int main(int argc, char** argv)
{
  return 0;
}


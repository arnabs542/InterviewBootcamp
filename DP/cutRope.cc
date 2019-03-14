/*
Comments :
Given a rope with length n, how should we cut the rope into m parts, with
lengths n[0], n[1] ... n[m-1], in order to get the maximal product of
n[0]*n[1]*...n[m-1]?
Conditions:
1. we have to cut atleast once
2. The cuts are whole numbers, i.e. no partial cuts allowed.
3. Assume that the length is atleast 2 units
*/

#include <iostream>
#include <limits>
#include <unordered_map>
#include <vector>

using namespace std;

// my solution
int maxProduct(int ropelength, int currlength, int lastcut, int product)
{
  if (currlength == ropelength)
    return product * (currlength - lastcut);

  return max(maxProduct(ropelength, currlength+1, currlength,
                        product*(currlength-lastcut)),
             maxProduct(ropelength, currlength+1, product,
                        lastcut));

}

int cutRope(int l , int L, unordered_map<int, int>& cache)
{
  if (l == 1)
    return 1;

  if (cache.find(l) != cache.end())
    return cache[l];

  int maxV = l == L ? 0 : l; // force a cut when l is the complete ropw, i.e
                             // must cut atleast once

  for (int c = 1; c < l; c++)
    maxV = max(maxV, c * cutRope(l-c, L ,cache));

  return cache[l] = maxV;
}

int cutRopeDP(int L)
{
  vector<int> dp(L+1, 0);
  dp[1] = 1;  // initialize with halting condition

  for (int l = 2; l <= L; ++l)
  {
    int maxV = (l == L) ? 0 : l;

    for (int c = 1; c < l; c++)
      maxV = max(maxV, c*dp[l-c]);

    dp[l] = maxV;
  }

  return dp[L];
}


int maxProductFromCutPieces(int ropelength) 
{
  unordered_map<int, int> cache;
  //return cutRope(ropelength,ropelength, cache);
  return cutRopeDP(4);
 // return maxProduct(ropelength, 0, 0, 1);
}

int main(int argc, char** argv)
{
  cout << maxProductFromCutPieces(4) << endl;
  return 0;
}


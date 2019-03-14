/*
Comments :
Given a sequence of matrices, find the most efficient way to multiply these
matrices together.
Given an array p[] which represents the chain of matrices such that the ith
matrix Ai is of dimension p[i-1]xp[i].
We need to write a function MAtrixChainOrder() that should return the minimum
number of multiplications needed to multiply the chain.
*/

#include <iostream>

using namespace std;

dp[i] = min(dp[i-1] + p[i-2]*p[i-1]*p[i], dp[i-2] + p[i-2]*p[i-1]*p[i] +
            p[i-3]*p[i-1]*p[i]);

int main(int argc, char** argv)
{
  return 0;
}


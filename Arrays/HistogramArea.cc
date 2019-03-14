/*
Comments :
Find the largest rectangular area possible in a given histogram where the
largest rectangle can be made of a number of contiguous bars. For simplicity all
bars have the same width of 1.
You will be given an array arr for the height of the bars. You have to answer q
queries, where in each query, you will be given left and right. For each query,
return the largest rectangular area possible in a histogram formed using
(right-left+1) bars with arrays of height arr[left], arr[left+1], arr[left+2]...
arr[right]
*/

#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <utility>

using namespace std;

map<pair<int, int>, int> htMap; //maps tuple (left, right) to the minimum height
                                // rectangle in the range [left, right]
long findMaxPossibleArea(vector<long> heights, int l, int r) {
{
  for (int i=0; i<heights.size(); ++i)
  {
    for (int j=i; j<heights.size(); ++j)
    {
      int minHt = numeric_limits<int>::max();
      for (int k=i; k <=j; ++k) {
        minHt = min(minHt, heights[j]);
      }
      hitMap[make_pair(i,j)] = minHt;
    }
  }

  return htMap[pair(left, right)]*(right-left+1);
}

int main(int argc, char** argv)
{
  return 0;
}


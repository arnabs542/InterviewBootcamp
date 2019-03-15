/*
 * Given an array of sorted integers (can be both positive and negative)
 * Square the numbers and return the resulting array in sorted order
 */


#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

void squareSorted(vector<int>& array)
{
  /// -3 -2 -1 0 1 2 3 4
  //  9 4 1 0 1 4 9 16

  int i;
  for (i=0; i < array.size() && array[i] < 0; ++i);

  transform(array.begin(), array.end(), array.begin(), multiplies<int>());

  if (i<0)
    return;

  int curr = array.size()-1, int j = 0;

  while (j < i)
  {
    if (array[j] > array[curr])
    {
      swap(array[j], array[curr]);
      
    }
  }
}

/*
 * Given an array find maximum (j-i), where j, i are indices in the array, such
 * that arr[j] > arr[i]
 */

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int findMaxHelper(vector<int>& array, int i, int j)
{
  if (i >= j)
    return -1;

  if (array[i] < array[j])
    return j-i;

  int res1 = findMaxHelper(array, i+1, j);
  int res2 = findMaxHelper(array, i, j-1);

  return res1 > res2 ? res1: res2;
}

int findMaximum(vector<int>& array)
{
  return findMaxHelper(array, 0, array.size()-1);
}

int main()
{
  vector<int> test1 = {1,2,3,4,5,6};
  vector<int> test2 = {5,4,3,2,1};
  vector<int> test3 = {3,2,9,1,0};
  
  assert(findMaximum(test1) == 5);
  assert(findMaximum(test2) == -1);
  assert(findMaximum(test3) == 2);

  return 0;
}

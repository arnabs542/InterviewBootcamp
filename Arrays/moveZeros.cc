/*
Comments :
Given an array nums, write a function to move all 0's to the end of it while
maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums
should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.

*/

#include <iostream>
#include <vector>

using namespace std;

void moveZeros(vector<int>& array)
{
  int i = 0;
  while (i < array.size() && array[i])
    ++i;

  int j=i+1;
  while (j < array.size() && !array[j])
    ++j;

  while ( j < array.size() && i < j)
  {
    swap(array[i], array[j]);

    while (i <= j && array[i])
      ++i;
    while (j < array.size() && !array[j])
      ++j;
  }
}

int main(int argc, char** argv)
{
  vector<int> array = {0,1,0,3,12};
  moveZeros(array);
  for (auto a: array)
    cout << a << " ";
  cout << endl;
  return 0;
}


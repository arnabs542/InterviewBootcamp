/*
Comments :
Problem : Find the minimum in a rotated, sorted array
We're given an array with sorted numbers. The array has been rotated an unknown
number of times. We need to find the minimum in such an array. Find a fast
method that uses constand space.
*/

#include <iostream>
#include <vector>

using namespace std;

int findMinimum(vector<int>& array)
{
  int begin=0, end = array.size()-1;

  while (begin < end)
  {
    int mid = begin + (end - begin)/2;

    if (array[begin] <= array[mid])
      begin = mid+1;
    else
      end = mid;
  }

  return array[begin];
}

int main(int argc, char** argv)
{
  vector<int> array = {2,3,1};
  cout << findMinimum(array) << endl;
  return 0;
}


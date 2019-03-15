#include <vector>
#include <iostream>
#include <cassert>

using std::vector;
using std::cout;
using std::endl;

int find(const vector<int>& array, int val)
{
  int left = 0, right = array.size()-1;

  while (left <= right)
  {

    int mid = left + (right-left)/2;

    if (array[mid] == val)
      return mid;

    if (array[mid] == array[left]) { ++left; continue; }
    if (array[mid] == array[right]) { ++right; continue; }

    if (array[mid] >= array[left]) {
      if (val < array[mid] && array[left] <= val)
        right = mid-1;
      else
        left = mid+1;
    }
    if (array[mid] <= array[right]) {
      if (val > array[mid] && array[right] >= val)
        left = mid+1;
      else
        right = mid-1;
    }
  }

  return -1;
}


int main()
{
  assert(find({15,16,19,20,25,1,3,4,5,7,10,14}, 5) == 8);
  assert(find({7,10,14,15,16,19,20,25,1,3,4,5}, 5) == 11);
  assert(find({4,5,7,10,14,15,16,19,20,25,1,3}, 5) == 1);
  assert(find({20,25,1,3,4,5,7,10,14,15,16,19}, 5) == 5);
  assert(find({1,1,3,1}, 3) == 2);
  return 0;
}

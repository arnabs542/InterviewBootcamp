/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Example 1:

Input: [1,3,4,2,2]
Output: 2
Example 2:

Input: [3,1,3,4,2]
Output: 3
Note:

You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than on
*/

#include <vector>
#include <utility>
#include <iostream>

using namespace std;

int count(const vector<int>& nums, int end)
{
  int count  = 0;

  for (auto n: nums)
    if (n <= end)
      ++count;

  return count;
}

int findDuplicate(const vector<int>& nums)
{
  int start=1, end=nums.size()-1;

  while (start < end)
  {
    int mid = start + (end-start)/2;
  
    if (count(nums, mid) <= mid)
    {
      start = mid+1;
    }
    else
    {
      end = mid-1;
    }
  }

  return end;
}

int main()
{
  vector<int> vec = {1,3,4,2,2};

  cout << findDuplicate(vec) << endl;
  return 0;
}

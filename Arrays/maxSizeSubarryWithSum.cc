/*Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

Note:
The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer range.

Example 1:

Input: nums = [1, -1, 5, -2, 3], k = 3
Output: 4 
Explanation: The subarray [1, -1, 5, -2] sums to 3 and is the longest.
Example 2:

Input: nums = [-2, -1, 2, 1], k = 1
Output: 2 
Explanation: The subarray [-1, 2] sums to 1 and is the longest.
Follow Up:
Can you do it in O(n) time?
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


// Complexity O(n^2)
int maxSubArrayLen(vector<int>& nums, int k)
{
  vector<int> cumulative;

  int sum=0;
  int maxLen = -1;

  for (auto n:nums) {
    sum += n;
    cumulative.push_back(sum);
  }

  for (int i=0; i < nums.size(); ++i)
  {
    for (int j=i; j < nums.size(); ++j)
    {
      int len; int sum = 0;
      if (i != 0) {
        sum = cumulative[j] - cumulative[i-1];
        len = j-i+1;
      }
      else {
        sum = cumulative[j];
        len = j+1;
      }

      if (sum == k)
        maxLen = max(len, maxLen);
    }
  }
  return maxLen;
}

// O(n) solution
int maxSubArrayLen2(vector<int>& nums, int k)
{
  unordered_map<int, int> m;  //store cumulative sums till various indices in the array

  int sum=0;  // cumulative sum
  int maxLen = 0;

  for (int i=0; i < nums.size(); ++i)
  {
    sum += nums[i];
    if (sum == k) {
      maxLen = i+1;  
    }
    else {
      if (m.count(sum-k))
        maxLen = max(maxLen, i-m[sum-k]);
    }
    if (!m.count(sum))
      m[sum] = i;
  }

  return maxLen;
}

int main()
{
  vector<int> test1 = {1, -1, 5, -2, 3};
  vector<int> test2 = {-2, -1, 2, 1};

  cout << maxSubArrayLen(test1, 3) << endl;
  cout << maxSubArrayLen(test2, 1) << endl;

  return 0;

}

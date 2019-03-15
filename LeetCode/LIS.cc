/*
Comments :
Given an unsorted array of integers, find the number of longest increasing
subsequence.

Example 1:
Input: [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3,
5, 7].
Example 2:
Input: [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and
there are 5 subsequences' length is 1, so output 5.
Note: Length of the given array will be not exceed 2000 and the answer is
guaranteed to be fit in 32-bit signed int.
*/

#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include <limits>
#include <unordered_map>

using namespace std;

void LISRec(const vector<int>& nums, map<int, int >&m, int index, int prev, int len)
{
	if (index == nums.size())
	{
		if (m.find(len) == m.end())
			m[len] = 1;
		else
			m[len]++;
		return;
	}

	if (nums[index] > prev) {
		LISRec(nums, m, index+1, nums[index], len+1);
	}
	LISRec(nums, m, index+1, prev, len);
}

int findNumberOfLIS(const vector<int>& nums) {
	map<int, int> m;
	LISRec(nums, m, 0, numeric_limits<int>::min(), 0);

	auto it = std::max_element(m.begin(), m.end());

	return it->second;
}

int findNumberOfLISDP(const vector<int>& nums)
{
  vector<int> table(nums.size(), 1);  // table[i] is the maxLen of sequence that ends at value at index i
  vector<int> count(nums.size(), 1);  // count[i] the number of different ways to arrive at a sequence ending with nums[i]
  int maxLen = 1;

  for (int i=1; i < nums.size(); ++i)
  {
    for (int j=0; j < i; ++j)
    {
      if (nums[j] < nums[i])
      {
        if (table[i] < table[j]+1)
        {
          table[i]   = table[j]+1;
          count[i] = count[j];
        }
        else if (table[i] == table[j]+1)
        {
          count[i] += count[j];
        }
      }
    }
    maxLen=max(table[i], maxLen);
  }

  int numberOfLIS=0;
  for (int i=0; i < nums.size(); ++i)
    if (table[i]==maxLen)
      numberOfLIS+=count[i];

  return numberOfLIS;
}

int main(int argc, char** argv)
{
	cout << findNumberOfLISDP({2,2,2,2,2}) << endl;
  return 0;
}

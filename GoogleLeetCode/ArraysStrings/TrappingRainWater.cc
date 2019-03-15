/*Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/

#include <vector>
#include <iostream>

using namespace std;

int trap(vector<int>& height)
{
  int left=0, right = height.size()-1;
  int leftmax = 0, rightmax = 0, water = 0;

  while (left <= right)
  {
    leftmax = max(leftmax, height[left]);
    rightmax = max(rightmax, height[right]);

    if (leftmax < rightmax) {
      if (leftmax > height[left])
        water += leftmax - height[left];
      ++left;
    } 
    else {
      if (rightmax > height[right])
        water += rightmax - height[right];
      --right;
    }
  }

  return water;
}

int main()
{
  vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
  cout << trap(height) << endl;

  return 0;
}

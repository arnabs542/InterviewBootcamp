/*
Comments :
Given an array of numbers nums, return an array of numbers products, where
products[i] is the product of all numbers nums[j], such that j != i

Solution summary : the recursive solution takes an argument fwdProduct and
return the revProduct
fwdProduct accumulates product of all numbers in array < element at index (for
the current recursive call)
revProduct accumulates product of numbers in array > element at index.
*/

#include <iostream>
#include <vector>

using namespace std;

int arrayProductRec(const vector<int>& nums, int fwdProduct, int index,
                     vector<int>& res)
{
  if (index == nums.size())
    return 1;

  // revProduct stores product of every number in array > index
  int revProduct = arrayProductRec(nums, fwdProduct*nums[index], index+1, res);
  // fwdProduct stores product of every number in array < index
  res[index] = fwdProduct*revProduct;
  return revProduct*nums[index];
}

vector<int> arrayProduct(const vector<int>& nums)
{
  int N = nums.size();
  vector<int> res(N, 0);
  arrayProductRec(nums, 1, 0, res);

  return res;
}

int main(int argc, char** argv)
{
  vector<int> nums = {1,2,3,4};
  vector<int> res = arrayProduct(nums);
  
  for (auto const& r : res)
    cout << r << " ";
  cout << endl;

  return 0;
}


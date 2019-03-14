/*
Comments :
Given an array of integers and a target K, return true or false, 
whether there is a group of integers (may or may not be contiguous)
in the input, that sums to K.

Sum({2,4,8},6) -> true
*/

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

bool sumOfIntegers(vector<int>& array, int index, int K)
{
  if (K==0)
    return true;
  if (index == array.size())
    return false;

  if (array[index] <= K && sumOfIntegers(array, index+1, K-array[index]))
    return true;
  return sumOfIntegers(array, index+1, K);
}

int main(int argc, char** argv)
{
  vector<int> a1 = {2,4,8};
  vector<int> a2 = {2,-4,8};
  
  assert(sumOfIntegers(a1,0,6));
  assert(sumOfIntegers(a2,0,1)==false);
  assert(sumOfIntegers(a1,0,14));
  assert(sumOfIntegers(a2,0,9)==false);
  return 0;
}


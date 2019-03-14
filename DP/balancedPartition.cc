/*
Comments :
Problem : Parition an array into two partitions,such that the sum of the two
halves is the same
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

bool balancedPartitionRec(int currIndex,  // the current index we are looking at
                          vector<int>& left, // the left partition indices
                          int leftSum, // the left parition sum
                          vector<int>& right, // the right partition indices
                          int rightSum, // the right partition sum
                          const vector<int>& arr, // the input array
                          vector<int>& resVec
                         )
{
  if (currIndex == arr.size())
  {
    if (leftSum == rightSum)
    {
      resVec.insert(resVec.end(), left.begin(), left.end());
      resVec.insert(resVec.end(), right.begin(), right.end());
      return true;
    }
    return false;
  }

  left.push_back(arr[currIndex]);
  if (balancedPartitionRec(currIndex+1, left, leftSum + arr[currIndex], right,
                        rightSum, arr, resVec))
    return true;

  left.pop_back();
  right.push_back(arr[currIndex]);
  bool res = balancedPartitionRec(currIndex+1, left, leftSum, right,
                           rightSum+arr[currIndex], arr, resVec);
  right.pop_back();
  return res;
}

vector<int> balancedPartition(vector < int > arr) 
{
  vector<int> left, right, res;
  balancedPartitionRec(0, left, 0, right, 0, arr, res);
  return res;
}

int main(int argc, char** argv)
{
  vector<int> arr = {4,1,-5,6,-11,3};
  for (auto v : balancedPartition(arr))
    cout << v << " ";
  cout << endl;
  return 0;
}


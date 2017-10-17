/*
Comments :
Given an array of N integers find all triplets that sume to 0 (zero)

Solution summary: brute force solution will look at all possible triplets
(O(n^3))

Given this, sorting is a relatively less expensive operation.
Sort the input, then if element i is part of the solution, then see if
(0-arr[i]) can be achieved with the rest if the array. 
Keep two pointers to the array, advance one or both depending on the current sum
value.
Complexity of this O( nlogn + n ^ 2) = O(n^2)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector < string > printTriplets(vector < int >& intArr) 
{
  sort(intArr.begin(), intArr.end());
  vector<string> res;

  for (int i = 0; i < intArr.size()-1; ++i)
  {
    int start = i+1; int end = intArr.size()-1;
    int sum = 0 - intArr[i]; // 2sum needed

    while (start < end)
    {
      if (start == i) 
      {
        ++start;
        continue;
      }
      if (end == i)
      {
        --end;
        continue;
      }

      int s = intArr[start] + intArr[end];

      if (s < sum)
      {
        ++start;
      }
      else if (s > sum)
      {
        --end;
      }
      else
      {
        string str = to_string(intArr[i]) + "," + to_string(intArr[start]) + "," +
            to_string(intArr[end]);
        res.push_back(str);
        ++start;
        --end;
      }
    }
  }

  return res;
}


int main(int argc, char** argv)
{
  vector<int> arr= {3, 12,34, -46};

  for (auto const& s : printTriplets(arr))
    cout << s << endl;
  return 0;
}


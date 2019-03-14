/*
Comments :
Problem : Given an array of integers, find a contiguous subarray whose sum is
zero. There can be duplicates in the input
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<string> sumZero(vector<int>& intArr)
{
  vector<string> res;
  unordered_map<int, vector<int> > table;

  int cumSum=0;
  for (int i=0; i < intArr.size(); ++i)
  {
    cumSum += intArr[i];
    if (table.find(cumSum) != table.end())
    {
      for (auto index : table[cumSum])
      {
        string str;
        for (int j = index+1; j <= i; ++j)
        {
          str += to_string(intArr[j]);
          if (j != i)
            str += ",";
        }
        res.push_back(str);
      }
    }

    table[cumSum].push_back(i) ;
  }

  return res;
}


int main(int argc, char** argv)
{
  vector<int> arr = {1,0};
  vector<string> res = sumZero(arr);
  for (auto const& s: res)
    cout << s << endl;
  return 0;
}


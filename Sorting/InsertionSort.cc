/*
Comments :
Implement insertion sort
*/

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

vector<int> insertionSort(vector<int>& array1)
{
  vector<int> array = array1;
  for (int i=1; i < array.size(); ++i)
  {
    int val = array[i];
    int j = i-1;
    while (j >= 0 && array[j] > val)
    {
      array[j+1] = array[j];
      --j;
    }
    array[j+1] = val;
  }
  return array;
}

void printVec(const vector<int>& array)
{
  for (auto v : array)
    cout << v <<  " ";
  cout << endl;
}

int main(int argc, char** argv)
{
  vector<int> test1 = {1,4,3,2};
  vector<int> test2 = {10,9,8,7,6};
  vector<int> test3 = {1,9,3,2,1,1};
  vector<int> test4 = {1};
  vector<int> test5 = {};
  vector<int> test11 = insertionSort(test1);
  vector<int> test22 = insertionSort(test2);
  vector<int> test33 = insertionSort(test3);
  vector<int> test44 = insertionSort(test4);
  vector<int> test55 = insertionSort(test5);

  sort(test1.begin(), test1.end());
  sort(test2.begin(), test2.end());
  sort(test3.begin(), test3.end());
  sort(test4.begin(), test4.end());
  sort(test5.begin(), test5.end());

  assert(test11 == test1);
  assert(test22 == test2);
  assert(test33 == test3);
  assert(test44 == test4);
  assert(test55 == test5);
  return 0;
}


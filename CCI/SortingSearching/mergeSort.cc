#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

void merge(vector<int>& array, int low, int mid, int high, vector<int>& helper)
{
  int index = low;
  int i=low, j=mid+1;

  while (i <= mid && j <= high)
  {
    if (array[i] < array[j]) {
      helper[index++] = array[i++];
    } else {
      helper[index++] = array[j++];
    }
  }

  if (i < mid) {
    helper[index++] = array[i++];
  }

  for (index = low; index <= high; ++index) {
    array[index] = helper[index];
  }
}

void mergeSortHelper(vector<int>& array, int low, int high, vector<int>& helper)
{
  if (low >= high)
    return;

  int mid = low + (high-low)/2;
  mergeSortHelper(array, low, mid, helper);
  mergeSortHelper(array, mid+1, high, helper);
  merge(array, low, mid, high, helper);
}

void mergeSort(vector<int>& array)
{
  vector<int> helper(array.size(), 0);
  mergeSortHelper(array, 0, array.size()-1, helper);
}

void printArray(const vector<int>& array)
{
  for (auto a: array)
    cout << a << ",";
  cout << endl;
}

int main()
{
  vector<int> array = {1,2,3,4,5,6,7,8,9,10};
  random_shuffle(array.begin(), array.end());
  printArray(array);
  mergeSort(array);
  printArray(array);

  return 0;
}

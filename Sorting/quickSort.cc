/*
Comments :
*/

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

void printArr(const vector<int>& vect)
{
  cout << "vector" << endl;

  for (auto v : vect)
    cout << v;
  cout << endl;
}

void swap(vector<int>& arr, int i, int j)
{
  assert(i < arr.size() && j < arr.size());

  int tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}

int partition(vector<int>& arr, int start, int end)
{
  int pivot = arr[start];
  int left = start+1;
  int right = end;

  while (left < right)
  {
    if (arr[left] < pivot)
      ++left;
    if (arr[right] > pivot)
      --right;
    if (arr[left] > arr[right]) swap(arr, left, right);
  }

  swap(arr, start, left);
  return start;
}

void quickSort(vector<int>& arr, int i, int j)
{
  if (i >= j)
    return;

  int pivotPosition = partition(arr, i, j);
  printArr(arr);
  quickSort(arr, i, pivotPosition-1);
  quickSort(arr, pivotPosition+1, j);
}

int main(int argc, char** argv)
{
  vector<int> arr = {4, 1, 5};
  quickSort(arr, 0, arr.size()-1);
  return 0;
}


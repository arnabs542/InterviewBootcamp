/*
Comments :
*/

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

void swap(vector<int>& array, int i, int j)
{
  int tmp = array[i];
  array[i] = array[j];
  array[j] = tmp;
}

int partition(vector<int>& array, int left, int right)
{
  int pivot = array[right];
  int pivotIndex = right;
  --right;

  while (left <= right)
  {
    if (array[left] <= pivot)
    {
      ++left;
    }
    else
    {
      swap(array, left, right);
      --right;
    }
  }

  swap(array, left, pivotIndex);
  return left;
}

void quickSortHelper(vector<int>& array, int left, int right)
{
  if (left >= right)
    return;

  int pivot = partition(array, left, right);
  quickSortHelper(array, left, pivot-1);
  quickSortHelper(array, pivot+1, right);
}


void quicksort(vector<int>& array)
{
  quickSortHelper(array, 0, array.size()-1);
}

int main()
{
  vector<int> array = {6, 5, 10,5, 7, 6, 3, 1, 4, 6, 2, 9, 8};
  quicksort(array);

  for (auto n:array)
    cout << n << " ";
  cout << endl;

  return 0;
}

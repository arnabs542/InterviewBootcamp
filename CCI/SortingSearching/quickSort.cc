#include <iostream>
#include <vector>
#include <random>

using std::vector;
using std::cout;
using std::endl;
using std::swap;

int partition(vector<int>& array, int low, int high)
{
  int pivotIndex = high;
  int pivot = array[high];

  int i = low, j = high-1;

  while(i <= j) {
    if (array[i] <= pivot)
    {
      ++i;
    }
    else
    {
      swap(array[i], array[j]);
      --j;
    }
  }

  swap(array[pivotIndex], array[i]);
  return i;
}

void quickSortHelper(vector<int>& array, int low, int high)
{
  if (low >= high)
    return;

  int pivotIndex = partition(array, low, high);
  quickSortHelper(array, low, pivotIndex-1);
  quickSortHelper(array, pivotIndex+1, high);
}

void quickSort(vector<int>& array)
{
  quickSortHelper(array, 0, array.size());
}

void printArray(const vector<int>& array)
{
  for (auto a: array)
    cout << a << ",";
  cout << endl;
}

int main()
{
  vector<int> array = {1,2,1,4,5,6,1,8,9,10};
  random_shuffle(array.begin(), array.end());
  printArray(array);
  quickSort(array);
  printArray(array);

  return 0;
}

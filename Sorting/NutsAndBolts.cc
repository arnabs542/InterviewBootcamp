/*
Comments :
A disorganized carpenter has a mixed pile of nuts and bolts and would like to
find the corresponding pairs of nuts and bolts. Each nut matched exactly one
bolt (and vice versa). By trying to match a bolt  and a nut the carpenter can
see which one is bigger, but she cannot compare two bolts or two nuts directly.
Can you help the carpenter match the nuts and bolts quickly.

You can make the following assumptions:
1. there are equal number of nuts and bolts
2. a given nut uniquely matches a bolt i.e. there are no extra unmatched nuts or
bolts i.e.  evey nut has one and only one matching bolt and vice vera.
*/

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

void swap(vector<int> &arr, int i, int j)
{
  assert(i >= 0 && j <= arr.size());
  int tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}

int partition(vector<int>& bolts, int left, int right, int nut)
{
  while (left < right) {
    if (bolts[left] < nut)
      ++left;
    if (bolts[right] > nut)
      --right;
    if (bolts[left] >= nut &&  bolts[right] <= nut)
      swap(bolts, left, right);
  }
  return left;
}

void findMatching(vector<int>& nuts, vector<int>& bolts)
{
  vector<int> pivotIndices;

  for (auto n : nuts) {
    int left = 0, right = bolts.size()-1;
    for (auto& p : pivotIndices)
    {
      int pivotIndex = p;
      if ( left < pivotIndex && bolts[pivotIndex] < n) {
        left = pivotIndex + 1;
      }

      if (right > pivotIndex && bolts[pivotIndex] > n) {
        right = pivotIndex - 1;
      }
    }
    int pIndex = partition(bolts, left, right, n);
    cout << "N" << n << "B" << bolts[pIndex] << endl;
    pivotIndices.push_back(pIndex);
  }
}

int main(int argc, char** argv)
{
  vector<int> nuts = {3,2,1,4};
  vector<int> bolts = {4,2,3,1};

  findMatching(nuts, bolts);

  return 0;
}


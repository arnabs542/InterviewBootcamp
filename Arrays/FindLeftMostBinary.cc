/*
Comments :
*/

#include <iostream>
#include <vector>

using namespace std;

int find(vector<int> array, int i, int j, int k)
{
  if (i > j)
    return i;

  int mid = i + (j-i)/2;
  if (array[mid] < k)
    return find(array, mid+1, j, k);
  if (array[mid] > k)
    return find(array, i, mid-1, k);
  if ((mid-1 >= 0) && (array[mid] == k) && array[mid-1] != k)
    return mid;
  else
    return find(array, i, mid-1, k);
}

int main(int argc, char** argv)
{
  vector<int> array = {1,1,2,2,2,3,3,4};
  cout << find(array, 0, array.size()-1, 2) << endl;
  return 0;
}


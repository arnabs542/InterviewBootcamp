#include <vector>
#include <iostream>

using namespace std;

void swap(vector<int>& array, int i, int j)
{
  int tmp = array[i];
  array[i] = array[j];
  array[j] = tmp;
}

void reverse(vector<int>& array)
{
  int i=0, j= array.size()-1;

  while (i<j)
  {
    swap(array, i, j);
    ++i; --j;
  }
}

int main()
{
  vector<int> array = {1,2,3,4};
  reverse(array);

  for (auto n: array)
    cout << n << " ";
  cout << endl;

  return 0;
}

#include <vector>
#include <cassert>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

void merge(vector<int>& a, vector<int>& b)
{
  int i = a.size() - b.size() - 1;
  int j = b.size() - 1;
  int k = a.size() - 1;

  cout << a.size() << "," <<  i << "," << j <<  "," << k << "," << endl;

  while (i >= 0 && j >= 0)
  {
    if (a[i] >= b[j])
      a[k--] = a[i--];
    else
      a[k--] = b[j--];
  }

  while (j >= 0)
    a[k--] = b[j--];
}


int main()
{
  vector<int> a(5, 0);
  vector<int> b = {2,4};
  a = {1,3,5,0,0};

  vector<int> res = {1,2,3,4,5};
  merge(a,b);
  assert(res == a);

  a = {1,2,3,0,0};
  b = {4,5};
  merge(a,b);
  assert(res == a);

  a = {4,5,0,0,0};
  b = {1,2,3};
  merge(a,b);
  assert(res == a);

  return 0;
}

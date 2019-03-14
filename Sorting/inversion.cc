/*
Comments :
Given a partially sorted array, find the number of inversion in the array

2, 4, 1, 3, 5
1, 2, 3, 4, 5

1,2,3,4,5  = 0
2,3,4,5,1  = 4
3,4,5,2,1


 
4,3
4,1
2,1
*/

#include <vector>
#include <iostream>

using namespace std;

void copy(vector<int>& src, vector<int>& dest, int begin, int end)
{
  for (int i=begin, k=0; i<=end && k < src.size();)
    dest[i++] = src[k++];
}


int merge(vector<int>& array, int left, int mid, int right)
{
  int i = left;
  int j = mid+1;
  int count  = 0;
  vector<int> res;

  while (i <= mid && j <= right)
  {
    if (array[i] <= array[j])
    {
      res.push_back(array[i++]);
    }
    else
    {
      res.push_back(array[j++]);
      count += mid-i+1;
    }                

  }

  while (i <= mid)
    res.push_back(array[i++]);
  while (j <= right)
    res.push_back(array[j++]);
  copy(res, array, left, right);
  return count;
}

int inversionRec(vector<int>& array, int left, int right)
{
  if (left >= right)
    return 0;

  int mid = left + (right - left)/2;
  int c1 = inversionRec(array, left, mid);
  int c2= inversionRec(array, mid+1, right);

  int c3 = merge(array, left, mid, right);
  return c1+c2+c3;
}

int inversion(vector<int>& array)
{
  return inversionRec(array, 0, array.size()-1);
}

int main(int argc, char** argv)
{
  vector<int> array = {2,3,4,5,1};
  cout << "inversions: " << inversion(array) << endl;
  return 0;
}


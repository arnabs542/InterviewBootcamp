/*
 * Find the median of two sorted arrays
 */

#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>

using namespace std;

double median(const vector<int>& v1) {
  auto size = v1.size();
  if (v1.size() % 2)
    return v1[size/2];
  return ( v1[size/2-1] +  v1[size/2])/2.0;
}

double medianOfTwo(const vector<int>& v1, const vector<int>& v2) {
  if (v1.empty())
    return median(v2);
  if (v2.empty())
    return median(v1);

  if (v2.size() < v1.size())
    medianOfTwo(v2, v1);

  size_t totalLen = v1.size() + v2.size();
  size_t midCount = (totalLen+1)/2;
  size_t low = 0, high = v1.size();

  while (low <= high) {
    int i = (low + high)/2;
    int j = midCount - i;
    int leftOfFirst = (i > 0)? v1[i-1]:numeric_limits<int>::min();
    int rightOfFirst = v1[i];
    int leftOfSecond = (j > 0)? v2[j-1] : numeric_limits<int>::min();
    int rightOfSecond = (j < v2.size())? v2[j]: numeric_limits<int>::max();

    if (leftOfFirst <= rightOfSecond && leftOfSecond <= rightOfFirst) {
      if ((totalLen % 2) == 0)
        return (max(leftOfFirst,leftOfSecond) + min(rightOfFirst, rightOfSecond))/2.0;
      else
        return max(leftOfFirst, leftOfSecond);
    }
    else if (leftOfSecond > rightOfFirst)
      low = i+1;
    else
      high = i-1;
  }
  return -1;
}

int main() {
  vector<int> v1 = {2,5,6,9,11};
  vector<int> v2 = {5,8,13,17};

  cout << std::setprecision(2) << medianOfTwo(v1, v2) << endl;

  return 0;
}

/*
Comments :
Given a point P and other N points in two dimensional space, find K points out
of the N points which are nearest to P

Solution Summary: Sort the N points using distance from P as a measure. Recurse
on the subarray where K lies
*/

#include <iostream>
#include <utility>
#include <vector>
#include <cmath>

using namespace std;

typedef pair<int, int> Point;
typedef vector<Point>  Points;

Point P;

bool operator<(const Point& a, const Point& b) 
{
  int distA = pow((a.first-P.first), 2) + pow((a.second-P.second), 2);
  int distB = pow((b.first-P.first), 2) + pow((b.second-P.second), 2);
  return distA < distB; 
}

bool operator>(const Point& a, const Point& b)
{
  return !(a<b);
}

void swap(Points& points, int i, int j)
{
  Point tmp = points[i];
  points[i] = points[j];
  points[j] = tmp;
}

int partition(Points& points, int start, int end)
{
  int i = start;
  int j = end-1;
  int pivot = end;

  while (i < j)
  {
    if (points[i] < points[pivot])
      ++i;
    if (points[j] > points[pivot])
      --j;
    if (points[i] > points[j])
      swap(points, i, j);
  }

  swap(points, pivot, i);
  return i;
}

void _findKClosest(Points& points, int start, int end, int K,
                   Points& res)
{
  if (start >= end ) {
    for (int i = 0; i < K; ++i)
    {
      res.push_back(points[i]);
    }
      return;
  }

  int pivotIndex = partition(points, start, end);

  if (pivotIndex == K) 
  {
    for (int i = 0; i < K; ++i)
    {
      res.push_back(points[i]);
    }
    return;
  }

  if (pivotIndex > K)
    _findKClosest(points, start, pivotIndex-1, K, res);
  else
    _findKClosest(points, pivotIndex+1, end, K, res);
}

void FindKClosest(Points& points, const Point& p, int K)
{
  Points res;
  P = p;
  _findKClosest(points, 0, points.size()-1, K, res);
  cout << "result: ";
  for (auto const& p : res)
    cout << "(" << p.first << "," << p.second << "),";
  cout << endl;

}

int main(int argc, char** argv)
{
  Points points = {{-2,-2}, {1,3}, {1,2}, {1,1}, {3,1}, {5,1}, {3,-2}, {6,-3}};
  Point p(3,2);
  FindKClosest(points, p, 2);
  return 0;
}

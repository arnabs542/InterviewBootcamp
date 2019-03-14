/*
Comments :
Given a set of time intervals in any order, merge all overlapping intervals into
one and output the result which should have only mutually exclusive intervals
Write a function that produces the set of merged intervals for the given set of
intervals

Solution summary : sort the intervals by start time and then end time: complexity O(nlog n)
Then merge using one pass through the intervals list O(n)
*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int>    Interval;
typedef vector<Interval>  Intervals;

struct MySort
{
  bool operator()(const Interval& i, const Interval& j)
  {
    return i.first < j.first ? true : (i.first > j.first) ? false : (i.second < j.second);
  }
} MyObject;

bool isOverlapping(const Interval& i, const Interval& j)
{ 
  return !(i.second < j.first);
}

Interval merge(const Interval& i, const Interval& j)
{
  return Interval(i.first, j.second);
}

void mergeIntervals(Intervals& input, Intervals& output)
{
  sort(input.begin(), input.end(), MyObject);

  Interval currInterval = input[0];

  for (int i = 1; i < input.size(); ++i)
  {
    if (isOverlapping(currInterval, input[i]))
    {
        currInterval = merge(currInterval, input[i]);
    }
    else
    {
      output.push_back(currInterval);
      currInterval = input[i];
    }
  }

  output.push_back(currInterval);
}

int main(int argc, char** argv)
{
  Intervals input = {{1,3}, {2,4}, {5,7}, {6,8}};
  Intervals output;
  mergeIntervals(input, output);

  for (auto const& i : output)
    cout << "{ " << i.first << "," << i.second << "}" << endl;
  return 0;
}


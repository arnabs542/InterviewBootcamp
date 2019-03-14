/*
Comments :
Given a sequence of words, and a limit on the number of charactes that can be
put on one line (line width). Put line breaks in the given sequence such that
the lines are printed neatly. Assume that the length of each word is smaller
than the line width.
The extra spaces includes spaces put at the end of each line.
Cost of a line = (Number of extra spaces in line)^3
Total cost = sum of costs of all lines
*/

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <cmath>

using namespace std;

int minSpaceCost(const vector<string>& strArr, int index, int lineWidth)
{
  if (index >= strArr.size())
    return 0;

  int wordLengthSoFar = 0;
  int minCost = numeric_limits<int>::max();
  for (int i=index; i<strArr.size(); ++i)
  {
    if (wordLengthSoFar)
      wordLengthSoFar += (strArr[i].size() + 1);
    else
      wordLengthSoFar += strArr[i].size();

    if (wordLengthSoFar > lineWidth)
      break;
    int empty = lineWidth - wordLengthSoFar;
    int cost = pow(empty, 3) + minSpaceCost(strArr, i+1, lineWidth);
    minCost = min(cost, minCost);
  }
  return minCost;
}

int minSpaceCost(const vector<string>& strArr, int lineWidth)
{
  return minSpaceCost(strArr, 0, lineWidth);
}

int main(int argc, char** argv)
{
  cout << minSpaceCost({"I",  "am", "Sam", "Kat"}, 5) << endl;
  return 0;
}


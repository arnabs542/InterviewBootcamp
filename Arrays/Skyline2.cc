/*
Comments :
*/


#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <set>

using namespace std;

vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {

  vector<pair<int, int>> res;
  multiset<int, greater<int> > active;
  multimap<int, int> criticalPoints;

  for (auto building : buildings) {
    criticalPoints.emplace(building[0], building[2]);   // start of rectangle
    criticalPoints.emplace(building[1], -building[2]);  // end of rectangle
  }

  for (auto point : criticalPoints)
  {
    int height = point.second;
    int x_coord = point.first;
    if (height > 0 )
    {
      active.emplace(height);
    }
    else
    {
      active.erase(active.find(-height));
    }

    res.push_back(make_pair(x_coord, *active.begin()));
  }

  int j=0;
  for (int i=1; i < res.size(); )
  {
    while (i < res.size() && res[i].second == res[j].second)
      ++i;

    if (i < res.size())
      res[++j] = res[i++];
  }

  for (; j < res.size()-1; ++j)
    res.pop_back();

  return res;

}

int main(int argc, char** argv)
{
  return 0;
}


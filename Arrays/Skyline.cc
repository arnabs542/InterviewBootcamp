/*
Comments :
You are given a set of rectangles in no particular order. They have varying
widths and heights, but their bottom edges are collinear, so they look like
buildings on a skyline.
For each rectangle, you're given the x position on the left edge
*/

#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;

typedef tuple<int, int, int> Building;
typedef tuple<int, int> RectStrip;

bool compFn(const Building& a, const Building& b)
{
  int i = get<0>(a);
  int j = get<0>(b);

  return i < j;
}

int getLeftCoordinate(const Building& b)  { return get<0>(b); }
int getBuildingHt(const Building& b)      { return get<1>(b); }
int getRightCoordinate(const Building& b) { return get<2>(b); }

void getSkyline(vector<Building>& buildings, vector<RectStrip>& strips
                /*out*/)
{
  map<int, priority_queue<int> > xPosToHt;
  sort(buildings.begin(), buildings.end(), compFn); // sort of the x coordinate of left side

  int maxRightCoord = numeric_limits<int>::min();

  for (auto const& building : buildings)
  {
    for (int x=getLeftCoordinate(building); x < getRightCoordinate(building); ++x)
    {
      int ht = getBuildingHt(building);
      xPosToHt[x].push(ht);
    }
    maxRightCoord = max(maxRightCoord, getRightCoordinate(building));
  }

  for (int x=getLeftCoordinate(buildings[0]); x <= maxRightCoord; ++x)
  {
    RectStrip strip = {x,0};
    if (xPosToHt.find(x) != xPosToHt.end())
      get<1>(strip) = xPosToHt[x].top();
    strips.emplace_back(strip);
  }

  int writeIndex=0;
  for (int i = 0; i < strips.size(); )
  {
    int j = i+1;
    while(get<1>(strips[j++]) == get<1>(strips[i]));
    strips[writeIndex++] = strips[i];
    i = j-1;
  }
  strips.resize(writeIndex);

}

// Only observe for critical points
void getSkyline(vector<Building>& buildings, vector<RectStrip>& strips)
{
  vector<int> criticalPoints;
  
  sort(buildings.begin(), buildings.end(), compFn); // sort of the x coordinate of left side

  for (auto const& building : buildings)
  {
    criticalPoints.push_back(getLeftCoordinate(building));
    criticalPoints.push_back(getRightCoordinate(building));
  }

  sort(criticalPoints.begin(), criticalPoints.end());

  for (auto const& cp : criticalPoints)
  {
  }
}

int main(int argc, char** argv)
{
  vector<RectStrip> strips;
  vector<Building> buildings = {{1,11,5}, {2,6,7}, {3,13,9}, {12,7,16},
    {14,3,25}, {19,18,22}, {23,13,29}, {24,4,28}};

  getSkyline(buildings, strips);

  for (auto const& strip : strips)
    cout << "( " << get<0>(strip) << "," << get<1>(strip) << ")" << ",";
  cout << endl;

  return 0;
}


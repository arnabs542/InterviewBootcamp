/*
Comments :
A group of farmers have some elevation data, and we;re going to help them
understand how rainfall flows over their farmland.
We'll represent the land as a two dimensional array of altitudes and use the
following model, based on the idea that water flows downhill.
If a cell's all four neighboring cells have higher altitudes, we call this cell
a sink; water collects in sinks.
Otherwise water will flow to the neighboring cell with lowest altitude. If a
cell is not a sink, you may assume that it has a unique lowest neighbor and that
this neighbor will be lower than the cell.
Cells that drain into the same sink - directly or indirectly -  are said to be
part of the same basin.
Challenge is to partition the map into basins. In particular given, given a map
of elevations, your code should parititon the map into basins and output the the
sizes of basins, in descending order.
Assume the elevation maps are squares ?? (how does this matter)
Some farmers have large land plots while some have small.
However in no case will a farmer have a plot larger than 5000.
Your code should output a space separated list of basin sizes, in descending
order.

Solution summary : The code below identifies all the sinks in the farm in the
first pass. A sink by definition is a position such that all neighbors (top,
down, left, right) have elevation greater than it.

In the second pass, try to grow the sinks into its neighbors (connected
components). The largest such area is the size of the basin, such that all cells drain into the same sink.
The condition for a cell to be part of the basin (drains into sink s) is
that the cell does not have any neighbor with altitude smaller than the sink.
Only explore neighbors with altitude strictly greater than the altitude of the
cell.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <set>

using namespace std;

typedef vector<vector<int> > Land; // 2-D vector representing altitude for Land
typedef pair<int, int> Location;   // Location of the land in the 2-D vector

vector<Location> neighVec = {{0,1}, {1,0}, {-1,0}, {0,-1}};

vector<Location> getNeighbors(const Location& loc, const Land& land)
{
  int M = land.size();
  int N = land[0].size();
  int r = loc.first, c = loc.second;

  vector<Location> neighbors;

  for (auto const& n : neighVec) {
    int r1 = r + n.first;
    int c1 = c + n.second;

    if ( r1 < M && r1 >= 0 && c1 < N && c1 >= 0 )
      neighbors.push_back(Location(r1, c1));
  }

  return neighbors;
}

void display(const set<Location>& s)
{
  for (auto const& loc: s)
    cout << loc.first << " " << loc.second << endl;
}

void identifySinks(const Land& land, set<Location>& sinks)
{

  for (int i = 0; i < land.size(); ++i)
  {
    for (int j = 0; j < land[0].size(); ++j)
    {
      bool isSink = true;
      for (auto const& n : getNeighbors(Location(i,j), land))
      {
        if (land[i][j] > land[n.first][n.second])
        {
          isSink = false;
          break;
        }
      }

      if (isSink)
        sinks.emplace(Location(i,j));
    }
  }
  //display(sinks);
}

int getBasinSize(const Location& sink, const Land& land, set<Location>& visited)
{
  int count = 0;

  queue<pair<Location, Location> > q;
  q.push(make_pair(sink, sink));

  while (!q.empty())
  {
    Location pos = q.front().first;
    Location parent = q.front().second;

    q.pop();

    if (visited.find(pos) != visited.end())
      continue;

    bool isPartOfBasin = true;

    vector<Location> neighbors = getNeighbors(pos, land);
    for (auto const& n : neighbors)
    {
      if (land[n.first][n.second] < land[parent.first][parent.second])
      {
        isPartOfBasin = false;
        break;
      }
    }

    if (isPartOfBasin)
    {
      visited.emplace(pos);

      for (auto const& n : neighbors) {
        if (land[n.first][n.second] > land[pos.first][pos.second])
          q.push(make_pair(n, pos));
      }

      ++count;
    }
  }

  return count;
}

void identifyBasins(const Land& land, const set<Location>& sinks,
                    vector<int>& basins)
{
  set<Location> visited;
  
  for (auto const& sink : sinks)
  {
    int count = getBasinSize(sink, land, visited);
    cout << "basin size: " << count << " for sink: (" << sink.first << "," <<
        sink.second << ")" << endl;
    basins.push_back(count);
  }
}

int main(int argc, char** argv)
{
  Land land = {{0, 2, 1, 3}, {2, 1, 0, 4}, {3, 3, 3, 3}, {5, 5, 2, 1}};

  set<Location> sinks;
  identifySinks(land, sinks);

  vector<int> basins;
  identifyBasins(land, sinks, basins);
  sort(basins.begin(), basins.end(), greater<int>());

  cout << "basins:" << endl; 
  for (auto const& s : basins)
    cout << s << " ";
  cout << endl;
  return 0;
}


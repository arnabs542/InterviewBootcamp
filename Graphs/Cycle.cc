/*
Comments :
Given a directed graph check whether there is a cycle in it

Solution Summary : Do a DFS on each node in the graph. Maintain a visited set.
This keeps a global account of nodes we've seen so far. For every node maintain
a set of nodes called path, which keeps account of the nodes we've seen while
doing DFS on this node. If we see a node again in path while doing DFS, we've
found a cycle.
*/

#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

typedef unordered_map<int, vector<int> > Graph;

bool hasCycleHelper(Graph& g, int node, set<int>& visited, set<int>& path)
{
  if (path.find(node) != path.end()) // there is a cycle
    return true;

  if (visited.find(node) != visited.end())  // we've already explored this
    return false;
  
  cout << "exploring node: " << node << endl;

  visited.emplace(node);
  path.emplace(node);

  for (auto const& neigh : g[node])
  {
    if (hasCycleHelper(g, neigh, visited, path))
      return true;
  }

  path.erase(node);
  return false;
}

bool hasCycle(Graph& g)
{
  set<int> visited;

  for (auto const& n : g)
  {
    set<int> path;
    if (hasCycleHelper(g, n.first, visited, path))
      return true;
  }
  return false;
}

int main(int argc, char** argv)
{
  Graph g;
  g[1].push_back(2);
  g[2].push_back(3);
  g[3].push_back(4);
  g[4].push_back(1);

  cout << hasCycle(g) << endl;
  return 0;
}


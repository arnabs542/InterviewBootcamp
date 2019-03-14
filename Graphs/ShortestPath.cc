/*
Comments :
Given two nodes in a graph find the shortest path b/w the two nodes

DFS does not guarantee finding the shortest path b/w two nodes. BFS does
guarantee a shortest path
The challenge is to be able to produce the path.
One possible solution is to maintain parent association b/w nodes in a table
while doing BFS. Once you visit the end node, reconstruct the path using the
parent associations. The parent association table also keeps track of the
visited nodes too.
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct Vertex
{
  int label;

  Vertex(int lab) : label(lab) {}
};

typedef unordered_map<Vertex*, vector<Vertex*> > Graph;
typedef stack<Vertex*> Path;

Path getShortestPath(Graph& g, Vertex* v1, Vertex* v2)
{
  queue<Vertex*> q;
  unordered_map<Vertex*, Vertex*> parents; // keeps track of visited nodes too
  Path p;

  cout << "Finding shortest path between: " << v1->label << " and " << v2->label
      << endl;

  q.push(v1);
  parents[v1] = nullptr;

  while (!q.empty())
  {
    Vertex* v = q.front();
    q.pop();
    if (v == v2)
      break;

    for (auto n : g[v])
    {
      if (parents.find(n) != parents.end())
        continue;
    
      parents[n] = v;
      q.push(n);
    }
  }

  // reconstruct the path
  Vertex* v = v2;
  while (v)
  {
    p.push(v);
    v = parents[v];
  }

  return p;
}

void constructGraph(Graph& g)
{
  Vertex* v1 = new Vertex(1);
  Vertex* v2 = new Vertex(2);
  Vertex* v3 = new Vertex(3);
  Vertex* v4 = new Vertex(4);
  Vertex* v5 = new Vertex(5);
  Vertex* v6 = new Vertex(6);

  g[v1].push_back(v3);  
  g[v1].push_back(v6);  

  g[v2].push_back(v4);

  g[v3].push_back(v1);
  g[v3].push_back(v4);
  g[v3].push_back(v5);

  g[v4].push_back(v2);
  g[v4].push_back(v3);

  g[v5].push_back(v3);

  g[v6].push_back(v1);
}

void printPath(stack<Vertex*>& path)
{
  while (!path.empty())
  {
    cout << path.top()->label << " ";
    path.pop();
  }
  cout << endl;
}

int main(int argc, char** argv)
{
  Graph g;
  constructGraph(g);

  for (auto it = g.begin(); it != g.end(); ++it)
  {
    Path p = getShortestPath(g, it->first, g.begin()->first);
    printPath(p);
  }

  return 0;
}


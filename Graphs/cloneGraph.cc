/*
Comments :
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

struct Vertex
{
  Vertex(int v) : val(v) {}

  int val;
  vector<Vertex*> neighs;
};

typedef vector<Vertex*> Graph;
typedef unordered_map<Vertex*, Vertex*> VertexMap;

void cloneVertex(Vertex* v, Vertex* v1, Graph* g1, VertexMap& vMap)
{
  for (Vertex* n : v->neighs)
  {
    if (vMap.find(n) != vMap.end())
    {
      v1->neighs.push_back(vMap[n]);
    } 
    else
    {
      Vertex *n1 = new Vertex(n->val);
      v1->neighs.push_back(n1);
      vMap[n] = n1;
      g1->push_back(n1);
    }
  }
}

Graph* cloneGraph(const Graph& g)
{
  Graph* g1 = new Graph();
  VertexMap vMap;

  for (Vertex* v : g )
  {
    if (vMap.find(v) == vMap.end())
    {
      Vertex* v1 = new Vertex(v->val);
      cloneVertex(v, v1, g1, vMap);
      g1->push_back(v1);
      vMap[v] = v1;
    }
  }

  return g1;
}

int main(int argc, char** argv)
{
  return 0;
}


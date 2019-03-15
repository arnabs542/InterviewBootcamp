#include <unordered_map>
#include <vector>
#include <iostream>
#include <queue>
#include <set>
#include <cassert>

using namespace std;

struct Node
{
  Node(int v): val(v) {}

  int val;
};

typedef unordered_map<Node*, vector<Node* > > Graph;


bool isThereRoute(Graph& g, Node* n1, Node* n2)
{
  queue<Node*> q;
  set<Node*> visited;

  q.emplace(n1);
  visited.emplace(n1);

  while (!q.empty())
  {
    for (auto n: g[q.front()])
    {
      if (n == n2)
        return true;

      if (visited.count(n))
        continue;
      visited.emplace(n);
      q.push(n);
    }
    q.pop();
  }
  return false;
}

void printGraph(Graph& g)
{
  for (auto edge : g)
  {
    cout << edge.first << " : ";
    for (auto n: edge.second)
      cout << n << " , ";
    cout << endl;
  }
}

int main()
{
  Graph g1, g2;

  Node n1(1), n2(2), n3(3), n4(4);

  cout << "n1: " << &n1 << endl;
  cout << "n2: " << &n2 << endl;
  cout << "n3: " << &n3 << endl;
  cout << "n4: " << &n4 << endl;
  

  // Construct graph1
  g1[&n2].push_back(&n3);
  g1[&n2].push_back(&n4);
  g1[&n4].push_back(&n1);

  cout << "graph1: " << endl;
  printGraph(g1);

  // Construct graph2
  g2[&n1] = {&n2};
  g2[&n3] = {&n2, &n4};
  g2[&n4] = {&n1};

  cout << "graph2: " << endl;
  printGraph(g2);
  
  assert(isThereRoute(g1, &n4, &n1) == true);
  assert(isThereRoute(g1, &n4, &n3) == false);
  assert(isThereRoute(g1, &n2, &n4) == true);

  assert(isThereRoute(g2, &n1, &n2) == true);
  assert(isThereRoute(g2, &n4, &n3) == false);
  assert(isThereRoute(g2, &n3, &n4) == true);

  return 0;
}

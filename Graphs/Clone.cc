#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct GraphNode {
  int label;
  vector<GraphNode*> neighbors;

  GraphNode(int v) : label(v) {}
};

unordered_map<GraphNode*, GraphNode*> map;

GraphNode* cloneGraph(GraphNode* node) {

  if (!node)
    return nullptr;

  if (map.count(node))
    return map[node];

  GraphNode* clone = new GraphNode(node->label);
  map[node] = clone;
  
  for (auto neigh: node->neighbors) {
    node->neighbors.push_back(cloneGraph(neigh));
  }
  return clone;
}

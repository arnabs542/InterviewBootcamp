/*
Comments :
Calculate the diameter of a tree. Diameter is the longest path between two
leaves of a tree. A path is the sum total of all distances(weights) attached to
all edges between two nodes. The tree is not necessarily binary.

solution summary: recursive solution. Each node returns the maximum depth upto
this node and also the maximum diameter. 
MaximumDiameter = max(max diamter amongst all its children, sum of two maximum
depths for all leaves reachable by this root)

Maximum Depth = max(depths of all leaves reachable from this node)

Each recursive function returns a pair of (maxDiameter, maxDepth) for leaves
reachable by the root node passed to this function

Think of edge cases and if this works for all of them.
*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <functional>
#include <sstream>

using namespace std;

struct TreeNode
{
  TreeNode(int v) : val(v) {}

  int val;
  vector<pair<TreeNode*, int> > children;
};

typedef pair<TreeNode*, int> Child;

pair<int, int> diameterHelper(TreeNode* root)
{
  if (!root)
    return make_pair(0,0);

  int maxDiameter = 0;
  priority_queue<int, vector<int>, greater<int> > heap;

  for (auto const& child : root->children)
  {
    pair<int, int> res = diameterHelper(child.first); // (diameter, depth)

    maxDiameter = max(maxDiameter, res.first);
    if (heap.size() == 2) 
    {
      if (heap.top() < res.second + child.second) 
      {
        heap.pop();
        heap.push(res.second + child.second);
      }
    }
    else
    {
      heap.push(res.second + child.second);
    }
  }

  int maxDepthSum=0;
  int maxDepth=0;
  while(!heap.empty())
  {
    maxDepthSum += heap.top();
    maxDepth = heap.top();
    heap.pop();
  }
  maxDiameter = max(maxDiameter, maxDepthSum);

  return make_pair(maxDiameter, maxDepth);
}

int diameter(TreeNode* root)
{
  pair<int, int> result = diameterHelper(root);
  return result.first;
}

pair<TreeNode*, int> constructTreeHelper(istringstream& is)
{
  TreeNode* root = nullptr;

  while (is.peek() == '}')
    is.get();
  char brace; int weight; int childCount;

  if (is >> brace >> weight >> childCount)
  {
    root = new TreeNode(0);
    for (int child = 1; child <= childCount; ++child) 
    {
      pair<TreeNode*, int> node = constructTreeHelper(is);
      root->children.push_back(node);
    }
  }
  return make_pair(root, weight);
}

TreeNode* constructTree(const string& inputStr)
{
  istringstream is(inputStr);
  return constructTreeHelper(is).first;
}


int main(int argc, char** argv)
{
  vector<pair<string, int> > testStrings = {
    {"{0 0}", 0},
    {"{0 1 { 5 0 } }", 5},
    {"{0 1 { 5 1 {4 1 { 7 0 }}}}", 16},
    {"{0 1 { 5 2 {8 0} {7 0}}}", 15},
    {"{0 3 {1 2 {5 0} {7 0}} {1 2 {6 0} {5 0}} {1 2 {10 0} {9 0}}}", 19},
    {"{0 3 {5 2 {8 0} {7 0}} {5 2 {9 0} {8 0}} {5 2 {10 0} {9 0}}}", 29}
  };

  for (auto const& test : testStrings)
  {
    TreeNode* root = constructTree(test.first);
    if (test.second == diameter(root))
      cout << test.first << " : " << "pass" << endl;
    else
      cout << test.first << " : " << "fail" << test.second << " "  << diameter(root) << endl;
  }

  return 0;
}


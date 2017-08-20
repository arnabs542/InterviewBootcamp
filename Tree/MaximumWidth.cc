/*
Comments :
Given a binary tree, write a function to get the maximum width of the given
tree. The width of a tree is the maximum width among all levels. The binary tree
has the same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes (the
leftmost and right most non-null nodes in the level, where the null nodes
between the end-nodes are also counted into the length calculation.

Example 1:
Input: 

           1

         /   \
        3     2
       / \     \
      5   3     9 

Output: 4
Explanation: The maximum width existing in the third level with the length 4
(5,3,null,9).
Example 2:
Input: 

          1
         /  
        3    
       / \
      5   3     

Output: 2
Explanation: The maximum width existing in the third level with the length 2
(5,3).

Solution summary : maintain a notion of node position in the tree , this is
identical to the arithmetic for node position in a heap. If root is at position
n, then :
left child position : 2*n
right child position : 2*n+1

Do a BFS of the tree, level by level. At each level calculate the width of the
nodes in the tree.
width at a level = right most node position - left most node position
return max width from all levels in tree
*/

#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>
#include <utility>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#if 0
int widthOfBinaryTree(TreeNode* root)
{
  TreeNode* specialNode = (TreeNode*) numeric_limits<int>::min();

  queue<TreeNode*> q;
  q.push(root);
  q.push(specialNode);

  int maxWidth = numeric_limits<int>::min();

  while (!q.empty())
  {
    int width = 0; int count = 0;
    while (!q.empty() && q.front() != specialNode)
    {
      TreeNode* node = q.front();
      q.pop();
      width++;
      
      if (node) {
        ++count;
        q.push(node->left);
        q.push(node->right);
      }
    }

    q.pop();
    if (!q.empty())
      q.push(specialNode);
    if (count >= 2)
      maxWidth = max(maxWidth, width);
    cout << "level: " << maxWidth << endl;
  }

  return maxWidth;
}
#endif

int widthOfBinaryTree(TreeNode* root)
{
  int nodeCount=1;

  queue<pair<TreeNode*, int> > q;
  q.push(make_pair(root, 1));
  int position = 1;

  int maxWidth = numeric_limits<int>::min();

  while (!q.empty())
  {
    int minCount = numeric_limits<int>::max();
    int maxCount = numeric_limits<int>::min();

    while (nodeCount)
    {
      TreeNode* node = q.front().first;
      int nodePos = q.front().second;
      minCount = min(q.front().second, minCount);
      maxCount = max(q.front().second, maxCount);
      q.pop(); --nodeCount;

      if (node->left || node->right)
      { 
        if (node->left)
          q.push(make_pair(node->left, 2*nodePos));
        if (node->right)
          q.push(make_pair(node->right, 2*nodePos+1));
      }
    }
    
    nodeCount = q.size();
    maxWidth = max(maxWidth, maxCount - minCount + 1);
  }
  return maxWidth;
}

TreeNode* constructTree()
{
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(3);
  root->right = new TreeNode(2);
  root->left->left = new TreeNode(5);
  root->right->right = new TreeNode(9);
  root->left->left->left = new TreeNode(1);
  root->right->right->right = new TreeNode(1);

  return root;
}

int main(int argc, char** argv)
{
  TreeNode* root = constructTree();
  cout << widthOfBinaryTree(root) << endl;
  return 0;
}


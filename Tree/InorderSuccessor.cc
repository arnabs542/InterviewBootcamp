/*
 * Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

Note: If the given node has no in-order successor in the tree, return null.

Example 1:

Input: root = [2,1,3], p = 1

  2
 / \
1   3

Output: 2
Example 2:

Input: root = [5,3,6,2,4,null,null,1], p = 6

      5
     / \
    3   6
   / \
  2   4
 /
1

Output: null
*/

#include <queue>
#include <utility>
#include <unordered_map>

using namespace std;

struct TreeNode
{
  TreeNode(int val): val(val), left(nullptr), right(nullptr) {}

  int       val;
  TreeNode* left;
  TreeNode* right;
};

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* node)
{
  if (node->right) {
    TreeNode* curr = node->right;

    while (curr && curr->left)
      curr = curr->left;
    return curr;
  }

  unordered_map<TreeNode*, TreeNode*> parent;
  parent[root] = nullptr;
  queue<TreeNode*> q;
  q.push(root);

  while (!q.empty())
  {
    auto curr = q.front(); q.pop();

    if (curr->left) {
      parent[curr->left] = curr;
      if (curr->left != node)
        q.push(curr->left);
    }
    if (curr->right) {
      parent[curr->right] = curr;
      if (curr->right != node)
        q.push(curr->right);
    }

    if (curr->left == node || curr->right == node)
      break;
  }

  TreeNode* curr = node;
  while (true) {
    assert(parent.count(curr) != 0);
    if (parent[curr]->left == curr)
      break;
    curr = parent[curr];
  }

  return parent[curr];
}

int main()
{
  TreeNode* root = new TreeNode(20);

  root->left = new TreeNode(10);
  root->left->left = new TreeNode(5);
  root->left->right = new TreeNode(15);

  root->right = new TreeNode(30);
  root->right->left = new TreeNode(25);
  root->right->right = new TreeNode(35);

  assert(inorderSuccessor(root, root)->val == 25);
  assert(inorderSuccessor(root, root->left->left)->val == 10);
  assert(inorderSuccessor(root, root->right)->val == 35);
  assert(inorderSuccessor(root, root->right->left)->val == 30);
  assert(inorderSuccessor(root, root->left)->val == 15);
  assert(inorderSuccessor(root,  root->left->right)->val == 20);

  return 0;
}

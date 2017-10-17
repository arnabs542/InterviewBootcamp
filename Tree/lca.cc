/*
Comments :
Find the least common ancestor of a rooted tree, given two nodes in the binary
tree.
1. the tree may/may not be a BST
2. assume a node structure with no parent pointers
3. Assume that the two nodes are distinct and exist in the tree
4. Find a solution that has runtime complexity O(N), N being the # of nodes in
the tree

Solution summary : recursively find the number of nodes that match the given
nodes. whenever the found # of nodes is 2, we've found the LCA for the two nodes
*/

#include <iostream>

using namespace std;

struct Node
{
  int val;
  Node* left;
  Node* right;
  Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

Node* findLCAHelper(Node* node, int n1, int n2, int& count)
{
  if (!node)
    return nullptr;


  Node* left=nullptr, *right=nullptr;

  int leftCount = count;
  if (left = findLCAHelper(node->left, n1, n2, leftCount))
    return left;

  int rightCount = count;
  if (right = findLCAHelper(node->right, n1, n2, rightCount))
    return right;
 
  count = leftCount + rightCount; 
  if (node->val == n1 || node->val == n2)
    count += 1;

  if (count == 2)
    return node;

  return nullptr;
}

Node* findLCA(Node* root, int n1, int n2)
{
  int count = 0;
  return findLCAHelper(root, n1, n2, count);
}

Node* createTree()
{
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);

  return root;
}

int main(int argc, char** argv)
{
  Node* root = createTree();
  Node* lca = findLCA(root, 3, 6);
  if (lca)
    cout << lca->val << endl;
  return 0;
}

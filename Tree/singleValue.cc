/*
Comments :
Given a binary tree, we need to count the number of unival subtrees(all nodes
that have the same value)
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

/*
   L=countLeftUnival, R=countRightUnival
   if isUnival(root) return L+R+1
   else return L+R
   Complexity of this solution = O(N^2)
bool isSingleValueHelper(Node* root, int val)
{
  if (!root)
    return true;

  return (root->val == val) && isSingleValueHelper(root->left, val) &&
      isSingleValueHelper(root->right, val);
}

bool isSingleValue(Node* root)
{
  return isSingleValueHelper(root->left, root->val) &&
      isSingleValueHelper(root->right, root->val);
}

int findSingleValueTrees(Node* node)
{
  if (!node)
    return 0;

  int left = findSingleValueTrees(node->left);
  int right = findSingleValueTrees(node->right);

  int n = isSingleValue(node) ? 1 : 0;

  return left + right + n;
}
*/

bool findSingleValueHelper(Node* node, int& count)
{
  if (!node)
    return true;

  int leftCount = count;
  bool left = findSingleValueHelper(node->left, leftCount);
  
  int rightCount = count;
  bool right = findSingleValueHelper(node->right, rightCount);

  
  if (left && right && (!node->left || node->left->val == node->val) &&
      (!node->right || node->right->val == node->val)) {
    count = leftCount + rightCount + 1;
    return true;
  }
  else
  {
    count = leftCount + rightCount;
    return false;
  }

}

int findSingleValueTrees(Node* node)
{
  int count = 0;
  findSingleValueHelper(node, count);
  return count;
}


Node* createTree()
{
  Node* root = new Node(1);
  root->left = new Node(1);
  root->right = new Node(1);
  root->left->left = new Node(1);
  root->left->right = new Node(1);
  root->right->right = new Node(1);

  return root;
}

int main(int argc, char** argv)
{
  Node* root = createTree();
  cout << findSingleValueTrees(root) << endl;
  return 0;
}


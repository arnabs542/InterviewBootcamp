#include <iostream>

struct Node
{
  Node(int v): val(v), left(nullptr), right(nullptr){}

  int     val;
  Node*   left;
  Node*   right;
};


int helper(Node* root, Node* n1, Node* n2, Node** res)
{
  if (!root)
    return 0;

  int leftCount = helper(root->left, n1, n2, res);
  if (leftCount == 2)
    return leftCount;

  int rightCount = helper(root->right, n1, n2, res);
  if (rightCount == 2)
    return rightCount;

  int count  = leftCount + rightCount;
  if (root == n1 || root == n2)
    count += 1;

  if (count == 2)
    *res = root;

  return count;
}


Node* findFirstCommonAncestor(Node* root, Node* n1, Node* n2)
{
  Node* res = nullptr;
  helper(root, n1, n2, &res);
  return res;
}

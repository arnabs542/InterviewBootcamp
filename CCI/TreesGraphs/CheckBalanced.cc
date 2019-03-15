#include <iostream>
#include <utility>
#include <cassert>

using namespace std;

struct Node
{
  Node(int v): val(v), left(nullptr), right(nullptr) {}

  int   val;
  Node* left;
  Node* right;
};


pair<bool, int> isBalanced(Node* root)
{
  if (!root)
    return {true, 0};

  auto left = isBalanced(root->left);
  if (!left.first)
    return left;
  auto right = isBalanced(root->right);
  if (!right.first)
    return right;

  if (abs(left.second - right.second) > 1)
    return {false, 0};
  return {true, max(left.second, right.second) + 1};
}


int main()
{
  Node* root = new Node(1);
  root->left = new Node(2);
  root->left->right = new Node(3);
  root->right = new Node(4);
  root->right->right = new Node(5);
  root->right->right->right = new Node(6);

  assert(isBalanced(root).first == false);
  
  root = new Node(1);
  root->left = new Node(2);
  root->left->right = new Node(3);
  root->right = new Node(4);
  root->right->right = new Node(5);
  assert(isBalanced(root).first == true);

  return 0;
}

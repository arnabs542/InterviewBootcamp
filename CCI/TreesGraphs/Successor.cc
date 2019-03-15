/*
 * Algorithm :
 * 1. If node has a right child, then successor is leftmost node of the right
 * subtree
 * 2.else If node is left child of parent, successor is the parent
 * 3. else successor is some parent node for which the child is a left node
 * 4. else nullptr
 */

struct Node{
  Node(int v): val(v), left(nullptr), right(nullptr), parent(nullptr) {}

  int   val;
  Node* left;
  Node* right;
  Node* parent;
};


Node* successor(Node* node)
{
  if (!node)
    return node;

  if (node->right) {
    Node* curr = node->right;
    while (curr->left)
      curr = curr->left;
    return curr;
  }

  Node* curr = node;
  if (curr->parent && curr->parent->left == curr) {
    return curr->parent;
    curr = curr->parent;
  }

  return nullptr;
}

#include <iostream>
#include <stack>

using namespace std;

struct Node {
  Node(int v): val(v), left(nullptr), right(nullptr) {}

  int   val;
  Node* left;
  Node* right;
};


// Solution1 : Recursive

bool validateHelper(Node* root, Node** prev)
{
  if (!root)
    return true;

  if (!validateHelper(root->left, prev))
    return false;

  if (*prev && (*prev)->val > root->val)
    return false;
  
  *prev = root;
  return validateHelper(root->right, prev);
}

bool validateBinaryTree(Node* root)
{
  Node* prev = nullptr;
  return validateHelper(root, &prev);
}


// Solution 2  : Iterative




bool validateBinaryTree2(Node* root)
{
  Node* prev = nullptr;
  stack<Node*> st;
  Node* curr = root;

  while (curr || !st.empty())
  {
    while (curr)
    {
      st.push(curr);
      curr = curr->left;
    }

    if (prev && prev->val >= st.top()->val)
      return false;

    prev = st.top(); st.pop();
    curr = prev->right;
  }

  return true;
}



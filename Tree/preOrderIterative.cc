#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int val): val(val), left(nullptr), right(nullptr) {}
};


void preorderIterative(TreeNode* node)
{
  stack<TreeNode*> st;


  while (!st.empty() || node)
  {
    if (node) {
      cout << node->val << " ";
      st.push(node);
      node = node ->left;
    } else {
      node = st.top()->right; st.pop();
    }
  }
}

TreeNode* constructTree()
{
  TreeNode* root = new TreeNode(10);
  root->left = new TreeNode(5);
  root->right = new TreeNode(15);
  root->left->left = new TreeNode(21);
  root->left->right = new TreeNode(33);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(20);

  return root;
}

int main(int argc, char** argv)
{

  TreeNode* root = constructTree();
  preorderIterative(root);
  return 0;
}


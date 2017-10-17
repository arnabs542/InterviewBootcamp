/*
Comments :
Print a binary tree in inorder iteratively

See template here :
https://discuss.leetcode.com/topic/46016/learn-one-iterative-inorder-traversal-apply-it-to-multiple-tree-questions-java-solution
 */

#include <iostream>
#include <stack>

using namespace std;

struct treeNode
{
  treeNode(int v) : val(v), left(nullptr), right(nullptr) {}

  int val;
  treeNode* left;
  treeNode* right;
};


void inorderIterative(treeNode* node)
{
  stack<treeNode*> st;

  while (node || !st.empty())
  {
    while (node) 
    {
      st.push(node);
      node = node->left;
    }

    cout << st.top()->val << " ";
    node = st.top()->right;
    st.pop();
  }
}

treeNode* constructTree()
{
  treeNode* root = new treeNode(10);
  root->left = new treeNode(5);
  root->right = new treeNode(15);
  root->right->left = new treeNode(6);
  root->right->right = new treeNode(20);

  return root;
}

int main(int argc, char** argv)
{

  treeNode* root = constructTree();
  inorderIterative(root);
  return 0;
}


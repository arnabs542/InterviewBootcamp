/*
Comments :
Given a binary tree, check if it is a BST.

See template in leetCode here: 

https://discuss.leetcode.com/topic/46016/learn-one-iterative-inorder-traversal-apply-it-to-multiple-tree-questions-java-solution
*/

#include <iostream>
#include <stack>

using namespace std;

struct treeNode
{
  treeNode(int v) : val(v), left(nullptr), right(nullptr) {}

  treeNode* left;
  treeNode* right;
  int val;
};

bool isBST(treeNode* node)
{
  treeNode* prev = nullptr;
  stack<treeNode*> st;

  while (node || !st.empty())
  {
    while (node)
    {
      st.push(node);
      node = node->left;
    }

    if (prev)
      if (prev->val >= st.top()->val)
        return false;

    prev = st.top(); st.pop();
    node = prev->right;
  }

  return true;
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
  cout << isBST(root) << endl;
  return 0;
}

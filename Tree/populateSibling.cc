/*
Comments :
Given a binary tree populate nextRight pointers in each node
Constraint : use only constant extra space

Given this:
        
          a
        /   \
      b      c
    /   \     \
   d     e     f


Turn it to this:

         a -> nil
       /   \
      b  ->  c -> nil
    /   \     \
   d ->  e ->  f -> nil

*/

#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode* nextRight;

  TreeNode(int v) : val(v), left(nullptr), right(nullptr), nextRight(nullptr){} 
};

void populateSiblings(TreeNode* root)
{
  queue<TreeNode*> q;
  q.push(root);

  int nodeCount=1;
  while (!q.empty())
  {
    while(nodeCount--)
    {
      TreeNode* node = q.front(); q.pop();
      if (nodeCount)
        node->nextRight = q.front();
      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);
    }
    nodeCount = q.size();
  }
}

TreeNode* constructTree1()
{
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->right->right = new TreeNode(5);
  return root;
}

TreeNode* constructTree2()
{
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->right->right = new TreeNode(5);
  return root;
}

void test(TreeNode* node, const string& expected)
{
  string str;

  while (node->nextRight) {
    str += to_string(node->nextRight->val);
    node = node->nextRight;
  }

  if (str == expected)
    cout << expected << " OK" << endl;
  else
    cout << expected << " not OK" << endl;
}

int main(int argc, char** argv)
{
  TreeNode* root = constructTree1();
  populateSiblings(root);
  test(root, "");
  test(root->left, "3");
  test(root->left->left, "45");

  root = constructTree2();
  populateSiblings(root);
  test(root, "");
  test(root->left, "3");
  test(root->left->left, "5");
  return 0;
}


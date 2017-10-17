/*
Comments :
*/

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode
{
  TreeNode* left;
  TreeNode* right;
  int val;

  TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

TreeNode* flip(TreeNode* root)
{
  if (!root)
    return nullptr;

  root->left = flip(root->right);
  root->right = flip(root->left);

  return root;
}

void printTree(TreeNode* root)
{
  queue<TreeNode*> q;
  q.push(root); q.push(nullptr);
  cout << "printTree" << endl;

  while(!q.empty())
  {
    while(!q.empty() && q.front()!= nullptr)
    {
      TreeNode* node = q.front(); q.pop();
      cout << node->val << " ";
      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);
    }
      
    cout << endl;

    q.pop();
    q.push(nullptr);
  }
}

int main(int argc, char** argv)
{
  TreeNode* root = new TreeNode(6);
  root->left = new TreeNode(3);
  root->right = new TreeNode(4);
  root->left->left = new TreeNode(7);
  root->left->right = new TreeNode(3);
  root->right->left = new TreeNode(8);
  root->right->right = new TreeNode(1);

  printTree(root);

  //printTree(flip(root));
  return 0;
}


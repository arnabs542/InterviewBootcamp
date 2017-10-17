/*
Comments :
Find the Kth element in order in a BST
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


void findKthBST(treeNode* root, int k)
{
  int K = k;
  if (!root)
  {
    cout << "empty tree" << endl;
    return;
  }

  stack<treeNode*> st;

  while (root || !st.empty())
  {
    while (root)
    {
      st.push(root);
      root = root->left;
    }

    --k;
    if (k==0)
    {
      cout << st.top()->val << endl;
      return;
    }

    root = st.top()->right; st.pop();
  }

  cout << K << " exceeds node count in BST" << endl;
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
  findKthBST(root, 1);
  findKthBST(root, 2);
  findKthBST(root, 3);
  findKthBST(root, 4);
  findKthBST(root, 5);
  findKthBST(root, 6);
  return 0;
}

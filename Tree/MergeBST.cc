/*
Comments :
Given two binary search trees merge them together to form another BST
The final tree should be a balance BST.
Also print the final tree level by level

Solution summary : Inorder traversal of the two trees gives two sorted arrays.
Merge them together and then use to form the balanced BST
*/

#include <iostream>
#include <vector>

using namespace std;

void inorderTraversal(Node* node, vector<int>& a)
{
  if (!node)
    return;

  inorderTraversal(node->left, a);
  a.push_back(node->val);
  inorderTraversal(node->right, a);
}

void merge(vector<int>& a1, vector<int>& a2, vector<int>& a3)
{
  int i = 0, j= 0;
  while (i < a1.size() && j < a2.size())
  {
    if (a1[i] < a2[j])
      a3.push_back(a1[i++]);
    else
      a3.push_back(a2[j++]);
  }

  while (i < a1.size())
    a3.push_back(a1[i++]);
  while (j < a2.size())
    a3.push_back(a2[j++]);
}

Node* formBSTHelper(const vector<int>& a, int i, int j)
{
  int mid = (j-i)/2;
  Node* root = new Node(a[mid]);
  root->left = formBST(a, i, mid-1);
  root->right = fromBST(a, mid+1, j);
  return root;
}

Node* formBST(const vector<int>& a)
{
  return formBSTHelper(a, 0, a.size()-1);
}

void printTreeLevelByLevel(Node* node)
{
  queue<Node*> q;
  q.push(node);
  q.push(nullptr);

  while (!q.empty())
  {
    while(!q.empty() && q.top() != nullptr)
    {
      Node* n = q.top();
      q.pop();
      if (n->left)
        q.push(n->left);
      if (n->right)
        q.push(n->right);
      cout << n->val << " ";
    }
    
    cout << endl;
    q.pop();
    if (!q.empty())
      q.push(nullptr);
  }
}

Node* mergeTrees(Node* n1, Node* n2)
{
  vector<int> a1, a2, a3;
  inorderTraversal(n1, a1);
  inorderTraversal(n2, a2);
  merge(a1, a2, a3);
  Node* root = formBST(a3);

  printTreeLevelByLevel(root);
  return root;

}

int main(int argc, char** argv)
{
  return 0;
}


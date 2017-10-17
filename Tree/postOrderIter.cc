/*
Comments :
Write a function to traverse a binary tree post order, without using recursion.
As you traverse, print contents of nodes
*/

#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

struct Node
{
  int val;
  Node* left;
  Node* right;
  Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

Node* createTree()
{
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);

  return root;
}

void postOrderIter(Node* root)
{
  typedef pair<Node*, int> NodeType;
  stack<NodeType> s;

  s.push(make_pair(root,0));

  while(!s.empty())
  {
    if (s.top().second) 
    {
      cout << s.top().first->val << " ";
      s.pop();
    }
    else
    {
      NodeType n = s.top(); s.pop();
      n.second = 1;
      s.push(n);


      if (n.first->right)
        s.push(NodeType(n.first->right, 0));
      if (n.first->left)
        s.push(NodeType(n.first->left, 0));
    }
  }
}


int main(int argc, char** argv)
{
  Node* root = createTree();
  postOrderIter(root);
  return 0;
}


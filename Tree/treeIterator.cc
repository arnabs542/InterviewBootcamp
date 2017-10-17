/*
Comments :
*/

#include <iostream>
#include <stack>

using namespace std;

struct Node
{
  int val;
  Node* left;
  Node* right;
  Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

class treeIterator
{
 public:
  treeIterator(Node* root) : node(root) {}
  int next();
  bool hasNext();

 private:
  Node*        node;
  stack<Node*> s;
};


int treeIterator::next()
{
  Node* n = nullptr;

  if (s.empty())
    n = node;
  else
    n = s.top();

  while (n && n->left)
  {
    s.push(n);
    n = n->left;
  }

  if (!s.empty() && n == s.top() && n->right)
  {
    s.push(n->right);
    s.pop();
  }

  if (!n) exit(1);
  return n->val;
}

bool treeIterator::hasNext()
{
  return !s.empty() || node;
}

Node* createTree()
{
  Node* root = new Node(35);
  root->left = new Node(20);
  root->right = new Node(50);
  root->left->left = new Node(15);
  root->left->right = new Node(25);
  root->right->left = new Node(40);
  root->right->right = new Node(55);

  return root;
}

int main(int argc, char** argv)
{
  Node *root = createTree();
  treeIterator it(root);

  if (it.hasNext())
    cout << it.next();
  cout << endl;
  return 0;
}


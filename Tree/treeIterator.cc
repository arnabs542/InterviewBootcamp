/*
Comments :
*/

#include <iostream>
#include <stack>
#include <exception>

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
  treeIterator(Node* root) 
  {
    pushAll(root);
  }

  int next();
  bool hasNext();

 private:
  void pushAll(Node* node)
  {
    for (; node ; s.push(node), node = node->left);
  }

  Node*        node;
  stack<Node*> s;
};


int treeIterator::next()
{
  Node* n = nullptr;

   if (s.empty())
     throw runtime_error("invalid next call on treeIterator");

   n = s.top(); s.pop();
   pushAll(n->right);
  return n->val;
}

bool treeIterator::hasNext()
{
  return !s.empty();
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

  while (it.hasNext())
    cout << it.next() << endl;
  return 0;
}


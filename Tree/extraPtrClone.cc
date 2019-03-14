/*
Comments :
Asked in the 3rd mock interview
Problem : Given a tree with an extra pointer pointing to a random node in the
tree, clone the tree
+--  1 <---+
|  2<>3    |
> 4--------+
 
 
    1 ---> put in the set pointer to node (1)
       2<>3 ---> check pointer in the set, " (2)
         4   
*/

#include <iostream>
#include <queue>
#include <unordered_map>


using namespace std;

struct Node
{
  int val;
  Node* left;
  Node* right;
  Node* extra;


  Node(int v) : val(v), left(nullptr), right(nullptr), extra(nullptr) {}
};


Node* cloneRec(Node* root, unordered_map<Node*, Node*>& m)
{
  if (!root)
    return nullptr;

  if (m.find(root) != m.end())
    return m[root];

  Node* node = new Node(root->val);
  m[root] = node;

  node->left  = cloneRec(root->left, m);
  node->right = cloneRec(root->right, m);
  node->extra = cloneRec(root->extra, m);

  return node;
}


Node* clone(Node* root)
{
  cout << "cloning" << endl;
  unordered_map<Node*, Node*> m;
  return cloneRec(root, m);
}

Node* createTree()
{
  Node* n1 = new Node(1);
  Node* n2 = new Node(2);
  Node* n3 = new Node(3);
  Node* n4 = new Node(4);

  n1->left = n2; n1->right = n3; n1->extra = n4;
  n2->left = n4; n2->extra = n3;
  n3->extra = n2;
  n4->extra = n1;

  return n1;
}


void printTree(Node* root)
{
  queue<Node*> q;
  q.push(root);

  cout << "Printing tree" << endl;
  while (!q.empty())
  {
    int count = q.size();
    while (count--)
    {
      Node* node = q.front();  q.pop();
      cout << node->val << 
          " " << (node->extra? node->extra->val : -1) << endl;

      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);
    }
  }
}

int main(int argc, char** argv)
{
  Node* root = createTree();
  printTree(root);

  Node* newRoot = clone(root);
  printTree(newRoot);
  return 0;
}


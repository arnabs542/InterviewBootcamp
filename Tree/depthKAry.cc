/*
Comments :
*/

#include <iostream>
#include <vector>
using namespace std;

#define K 3

struct Node
{
    Node(int v) : val(v), child(K, nullptr) {}
    int val;
    vector<Node*> child;
};

int findHeight(Node* root)
{
    if (!root)
        return 0;
    
    int height = 0;
    
    
    for (Node* node : root->child)
    {
        int h = findHeight(node);
        height = max(h, height);
    }
    return height+1;
}

Node* constructTree()
{
    Node *root = new Node(1);
    root->child[0] = new Node(1);
    root->child[1] = new Node(1);
    root->child[2] = new Node(2);
    
    root->child[0]->child[0] = new Node(3);
    return root;
}

int main() {
  Node * root = constructTree();
  cout << findHeight(root) << endl;
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  return 0;
}




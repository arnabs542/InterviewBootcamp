/*
Comments :
*/

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct treeNode
{
  treeNode* left;
  treeNode* right;
  int val;
};

void inorder(treeNode* node)
{
  inorder(node->left);
  cout << node->val;
  inorder(node->right);
}

void preOrderIterative(treeNode* root)
{
  stack<treeNode*> s;
  s.push(root);

  while (!s.empty()) {
    treeNode* node = s.top();
   
    cout << node->val;
    s.pop();
    
    if (node->right)
      s.push(node->right);
    if (node->left)
      s.push(node->left);
  }
}

void bfs(treeNode* root)
{
  queue<treeNode*> q;

  q.push(root);

  while(!q.empty())
  {
    treeNode* node = q.front();
    q.pop();

    cout << node->val;

    q.push(node->left);
    q.push(node->right);
  }
}


void printLevel(treeNode* root)
{
  typedef pair<treeNode*, int> NodeLevelT;

  queue<NodeLevelT> q;

  int currLevel = 1;
  q.push(make_pair(root, currLevel));

  while (! q.empty())
  {
    NodeLevelT& n = q.front();
  }
}
  

int main(int argc, char** argv)
{
  return 0;
}


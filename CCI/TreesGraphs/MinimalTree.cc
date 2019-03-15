#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
  Node(int v): val(v), left(nullptr), right(nullptr) {}

  int   val;
  Node* left;
  Node* right;
};

void printTree(Node* root)
{
  queue<Node*> q;
  q.push(root);
  int count = 1;

  while (!q.empty())
  {
    int newCount = 0;
    while (count--)
    {
      Node* currNode = q.front(); q.pop();
      cout << currNode->val << " ";
      if (currNode->left) { q.push(currNode->left); ++newCount; }
      if (currNode->right) { q.push(currNode->right); ++newCount; }
    }
    cout << endl;
    count = newCount;
  }
}

Node* treeHelper(vector<int>& array, int left, int right)
{
  if (left > right)
    return nullptr;

  int mid = left + (right - left)/2;

  Node* root = new Node(array[mid]);
  root->left = treeHelper(array, left, mid-1);
  root->right = treeHelper(array, mid+1, right);
  return root;
}

Node* minimalTree(vector<int>& array)
{
  return treeHelper(array, 0, array.size()-1);
}

int main()
{
  vector<int> array = {1,2,3,4,5,6,7,8};

  Node* root = minimalTree(array);
  printTree(root);

  return 0;
}

/*
Comments :
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;

struct Node
{
  int val;
  Node* left;
  Node* right;

  Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

void constructIndexMap(const vector<int>& inorder, unordered_map<int, int>& m)
{
  for (int i = 0 ; i < inorder.size(); ++i)
    m[inorder[i]] = i;
}

#if 0
Node* constructTreeRec(const int* inorder,
                       int start,
                       int end,
                       const int* preorder,
                       int preIndex,
                       unordered_map<int, int>& m)
{
  cout << "start: " << start << "end: " << end << "preorder: " << preIndex << endl;
  if (start > end) return nullptr;

  Node* root = new Node(preorder[preIndex]);
  int rootIndex = m[root->val];

  if (start < end) {
  root->left  = constructTreeRec(inorder, start,       rootIndex-1, preorder, preIndex+1, m);
  root->right = constructTreeRec(inorder, rootIndex+1, end,         preorder, rootIndex+1, m);
  }
  return root;
}
#endif

Node* constructTreeRec(const int* inorder, const int* preorder, int n , int
                       offset, const unordered_map<int, int>& m)
{
  if (n==0)
    return nullptr;
  
  cout << "n << " << n  << "offset: " << offset << endl;

  int rootVal = preorder[0];
  int rootIndex = m.find(rootVal)->second - offset;
  Node * root = new Node(rootVal);

  root->left = constructTreeRec(inorder, preorder+1, rootIndex, offset, m);
  root->right = constructTreeRec(inorder+rootIndex+1, preorder+rootIndex+1,
                                 n-rootIndex-1, offset+rootIndex+1, m);

  return root;
}


void printTree(Node* root)
{
  queue<Node*> q;
  q.push(root);

  while (!q.empty())
  {
    int count = q.size();

    while (count)
    {
      Node* node = q.front(); q.pop();
      --count;

      cout << node->val << " ";

      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);
    }

    cout << endl;

    if (q.empty())
      break;
  }
}


void constructTree(const vector<int>& inorder, const vector<int>& preorder)
{
  unordered_map<int, int> valueToIndexMap;
  constructIndexMap(inorder, valueToIndexMap);
  Node* root = constructTreeRec(inorder.data(), preorder.data(), inorder.size(),
                                0, valueToIndexMap);
  printTree(root);
}

int main(int argc, char** argv)
{
  constructTree({113,
                435,
                1347,
                2405,
                2719,
                3093,
                4065,
                4135,
                4478,
                5086,
                5771,
                6260,
                6307,
                6728,
                7663,
                7904,
                8595,
                9278,
                9750,
                9898}, 
               
              {4478,
              435,
              113,
              2405,
              1347,
              2719,
              4135,
              3093,
              4065,
              5086,
              9750,
              9278,
              8595,
              6307,
              5771,
              6260,
              7904,
              6728,
              7663,
              9898});
  return 0;
}


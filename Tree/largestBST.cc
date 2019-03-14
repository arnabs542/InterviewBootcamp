/*
Comments :
*/

#include <iostream>
#include <tuple>
#include <limits>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

typedef tuple<bool /*isBST*/, int /*size*/, int /*minVal*/, int /*maxVal*/, int/*maxBST so far*/> ResType;

struct Node
{
  int val;
  Node* left;
  Node* right;

  Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

void printTreeLevelByLevel(Node* node)
{
  queue<Node*> q;
  q.push(node);
  q.push(nullptr);

  while (!q.empty())
  {
    while(!q.empty() && q.front() != nullptr)
    {
      Node* n = q.front();
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

ResType findLargest(Node* node)
{
  if (!node)
    return ResType(true, 0, numeric_limits<int>::max(),
                   numeric_limits<int>::min(), 0);

  if (!node->left && !node->right)
    return ResType(true, 1, node->val, node->val, 1);

  ResType left = findLargest(node->left);
  ResType right = findLargest(node->right);

  int maxBST = max(get<4>(left),  get<4>(right));

  ResType res;

  // Check if BST property holds for the tree rooted at node 'node'
  if (get<0>(left) && get<0>(right) /*both the left and right subtrees are BSTs*/
      &&
      get<3>(left) < node->val /* largestVal in left subtree is strictly less
                                  than node*/
      &&
      node->val < get<2>(right)) /*current node value is strictly less
                                     than the smallest value in right subtree*/
  {
    maxBST = max(maxBST, get<1>(left) + get<1>(right) + 1);
    res = ResType(true, get<1>(left)+get<1>(right)+1, get<2>(left),
                  get<3>(right), maxBST);
  }
  else
  {
    res = get<1>(left) > get<1>(right) ? left : right;
    get<0>(res) = false;
    get<4>(res) = maxBST;
  }

  return res;
}

int findLargestBST(Node* node)
{
  ResType res = findLargest(node);
  return get<4>(res);
}

Node* deserialize(istringstream& in)
{
  if (in.eof()) return nullptr;

  string val;
  in  >> val;

  if (val.empty()) return nullptr;

  if (val == "#") return nullptr;

  Node* root = new Node(stoi(val));
  root->left = deserialize(in);
  root->right = deserialize(in);
  return root;
}

Node* createTree( string data)
{
  if (data.empty()) return nullptr;
  istringstream in(data);
  return deserialize(in);
}


int main(int argc, char** argv)
{
  Node* root = createTree("99 9855 9476 10 2964 2246 1523 1203 -21 # 839 40 3 # # 619 549 # # # 979 862 # # # 1211 # 1464 # # 1944 1873 # # 2020 # # 2371 # 2829 2461 2452 # # 2462 # # # 3066 # 2968 # # # 4564 4223 3998 3698 # # # 4377 4305 # # # 6283 5021 # 6120 # # 7843 # 6704 6600 # # 7278 # # 9462 8806 8398 7954 7925 # # # # 9114 # 9291 # # # 9772 # 9623 # # # # ");
  printTreeLevelByLevel(root);
  cout << "largestBST: " << findLargestBST(root) << endl;
  return 0;
}


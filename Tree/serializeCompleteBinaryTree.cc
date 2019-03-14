#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

/* For a complete binary tree, it is possible to serialize/deserialize using
 * level by level order*/

struct TreeNode
{
  TreeNode(int val): left(nullptr), right(nullptr), val(val) {}

  TreeNode* left;
  TreeNode* right;
  int       val;
};

bool isEqual(TreeNode* root1, TreeNode* root2)
{
  stack<TreeNode*> st1, st2;
  st1.push(root1);
  st2.push(root2);

  if (root1 && !root2)
    return false;
  if (!root1 && root2)
    return false;


  while (!st1.empty() && !st2.empty())
  {
    auto node1 = st1.top(); st1.pop();
    auto node2 = st2.top(); st2.pop();

    if (node1->val != node2->val)
      return false;

    if ((node1->left && !node2->left) || (!node1->left && node2->left))
      return false;
    if (node1->left && node2->left)
    {
      st1.push(node1->left);
      st2.push(node2->left);
    }
    if ((node1->right && !node2->right) || (!node1->right && node2->right))
      return false;
    if (node1->right && node2->right)
    {
      st1.push(node1->right);
      st2.push(node2->right);
    }
  }

  return true;
}

TreeNode* deserialize(const vector<int>& array)
{
  if (array.empty())
    return nullptr;

  int index = 0;
  TreeNode* root = new TreeNode(array[index++]);
  queue<TreeNode*> q; q.push(root);

  while (index < array.size())
  {
    TreeNode* node = q.front(); q.pop();

    node->left = new TreeNode(array[index++]);
    if (index < array.size())
      node->right = new TreeNode(array[index++]);

    if (node->left)
      q.push(node->left);
    if (node->right)
      q.push(node->right);
  }

  return root;
}


vector<int> serialize(TreeNode* root)
{
  vector<int> res;
  if (!root)
    return res;

  queue<TreeNode*> q;
  q.push(root);
  int count = 1;

  while (!q.empty())
  {
    int newCount = 0;

    while (count--)
    {
      TreeNode* node = q.front(); q.pop();
      res.push_back(node->val);

      if (node->left) {
        q.push(node->left);
        ++newCount;
      }
      if (node->right) {
        q.push(node->right);
        ++newCount;
      }
    }
    count = newCount;
  }

  for (auto n: res)
    cout << n << ",";
  cout << endl;

  return res;
}

void printTreeLevelByLevel(TreeNode* node)
{
  queue<TreeNode*> q;
  q.push(node);
  q.push(nullptr);

  while (!q.empty())
  {
    while(!q.empty() && q.front() != nullptr)
    {
      TreeNode* n = q.front();
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

int main()
{
  TreeNode* root = new TreeNode(7);
  root->left = new TreeNode(5);
  root->right = new TreeNode(10);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(6);
  root->right->left= new TreeNode(8);
  root->right->right = new TreeNode(15);

  assert(isEqual(root, deserialize(serialize(root))));

  return 0;
}

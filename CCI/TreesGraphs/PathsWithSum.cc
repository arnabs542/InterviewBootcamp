#include <iostream>
#include <unordered_map>

struct Node
{
  Node(int v): val(v), left(nullptr), right(nullptr) {}

  int   val;
  Node* left;
  Node* right;
};


void _helper(Node* root, int target, int& result, int& sum, std::unordered_map<int, int>& runningSums)
{
  if (!root)
    return;


  sum += root->val;

  if (runningSums.count(sum - target))
    result += runningSums[sum-target];
  if (sum == target)
    ++result;

  if (runningSums.count(sum))
    ++runningSums[sum];
  else
    runningSums.emplace(sum, 1);

  _helper(root->left, target, result, sum, runningSums);
  _helper(root->right, target, result, sum, runningSums);

  --runningSums[sum];
  if (runningSums[sum] == 0)
    runningSums.erase(sum);
  sum -= root->val;

}

int getPaths(Node* root, int target)
{
  std::unordered_map<int, int> runningSums;
  int sum = 0;
  int result = 0;

  _helper(root, target, result, sum, runningSums);
  return result;
}


int main()
{
  Node* root = new Node(7);
  
  root->left = new Node(-4);
  root->right = new Node(8);

  root->left->left = new Node(5);
  root->left->right = new Node(-2);

  root->right->left = new Node(-5);
  root->right->right = new Node(-12);

  std::cout << "paths:" << getPaths(root, 3) << std::endl;

  return 0;
}

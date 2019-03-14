#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};


TreeNode* makeTree(const vector<int>& list, int low, int high)
{
  if (low > high)
    return nullptr;

  int midIndex = low + (high-low)/2;
  TreeNode* node = new TreeNode(list[midIndex]);
  node->left = makeTree(list, low, midIndex-1);
  node->right = makeTree(list, midIndex+1, high);

  return node;
}

void printTree(TreeNode* root)
{
  queue<TreeNode*> q;
  int count = 0;

  if (root) {
    q.push(root);
    ++count;
  }

  while (!q.empty()) {
    int nextCount = 0;

    while(count--) {
      cout << q.front()->val << " ";

      if (q.front()->left) {
        q.push(q.front()->left);
        ++nextCount;
      }
      if (q.front()->right) {
        q.push(q.front()->right);
        ++nextCount;
      }

      q.pop();
    }
    cout << endl;
    count = nextCount;
  }

}


int main()
{
  vector<int> list = {34,12,5,-9,13,1,0,3,21,342};
  sort(list.begin(), list.end());

  printTree(makeTree(list, 0, list.size()-1));

  return 0;
}

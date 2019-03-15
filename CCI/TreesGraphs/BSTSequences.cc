#include <iostream>
#include <vector>

using namespace std;

struct Node
{
  Node(int v): val(v), left(nullptr), right(nullptr) {}

  int   val;
  Node* left;
  Node* right;
};

void helper(vector<int>& p, int i, vector<int>& q, int j, vector<int>& merged, vector<vector<int> >& res)
{
  if (i == p.size() && j == q.size())
  {
    res.push_back(merged);
    return;
  }

  if (i < p.size())
  {
    merged.push_back(p[i]);
    helper(p, i+i, q, j, merged, res);
    merged.pop_back();
  }
  if (j < q.size())
  {
    merged.push_back(q[i]);
    helper(p, i, q, j+1, merged, res);
    merged.pop_back();
  }
}

void interleave(vector<vector<int> >& p, vector<vector<int> >& q, int val, vector<vector<int> >& res)
{
  vector<int> merged = {val};

  if (p.empty() && q.empty())
  {
    res.push_back(merged);
    return;
  }

  if (p.empty() || q.empty())
  {
    vector<int> empty;
    if (p.empty())
    {
      for (int i=0; i < q.size(); ++i)
        helper(empty, 0, q[i], 0, merged, res);
    }
    if (q.empty())
    {
      for (int i=0; i < p.size(); ++i)
        helper(empty, 0, p[i], 0, merged, res);
    }
  }

  for (int i = 0; i < p.size(); ++i)
    for (int j=0; j < q.size(); ++j)
      helper(p[i], 0, q[j], 0, merged, res);
}

vector<vector<int> > getSequences(Node* root)
{
  if (!root)
    return vector<vector<int> >();

  vector<vector<int> > left = getSequences(root->left);
  vector<vector<int> > right = getSequences(root->right);
  vector<vector<int> > merged;

  interleave(left, right, root->val, merged);
  return merged;
}

int main()
{
  Node* root = new Node(2);
  root->left = new Node(1);
  root->right = new Node(3);

  for (auto s: getSequences(root))
  {
    for (auto n: s)
      cout << n << ",";
    cout << endl;
  }
  return 0;
}

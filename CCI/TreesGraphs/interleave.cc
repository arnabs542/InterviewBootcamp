
#include <vector>
#include <iostream>

using namespace std;

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
    //merged.pop_back();
  }
  if (j < q.size())
  {
    merged.push_back(q[i]);
    helper(p, i, q, j+1, merged, res);
    //merged.pop_back();
  }
}

int main()
{
  vector<int> a = {1,2};
  vector<int> b = {3,4};

  vector<int> merged;
  vector<vector<int> > res;

  helper(a, 0, b, 0, merged, res);

  for (auto v: res)
    for (auto n: v) 
      cout << n << " ";
  cout << endl;

  return 0;
}

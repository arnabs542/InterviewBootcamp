#include <vector>
#include <iostream>


using namespace std;



void getSubsets(vector<int>& set, vector<int>& res, int index)
{
  if (index == set.size())
  {
    cout << "{ ";
    for (auto n: res)
      cout << n <<",";
    cout << "}" << endl;
    return;
  }

  getSubsets(set, res, index+1);
  res.push_back(set[index]);
  getSubsets(set, res, index+1);
  res.pop_back();

}

int main()
{
  vector<int> set = {1,2,3,4,5};
  vector<int> res;
  getSubsets(set, res, 0);

  return 0;
}

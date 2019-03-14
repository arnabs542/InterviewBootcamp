#include <iostream>
#include <vector>

using namespace std;

void subsets(vector<int>& array, size_t index, vector<vector<int> >& res, vector<int>& pRes)
{
  if (index == array.size()) {
    res.push_back(pRes);
    return;
  }

  subsets(array, index+1, res, pRes);
  pRes.push_back(array[index]);
  subsets(array, index+1, res, pRes);
  pRes.pop_back();
}

int main()
{
  vector<int> array = {1,2,3};
  vector<vector<int> > res;
  vector<int> pRes;
  subsets(array, 0, res, pRes);

  for (auto a: res) {
    cout << "{ ";
    for (auto e: a) {
      cout << e << ",";
    }
    cout << "}";
  }
  cout << endl;

  return 0;
}
  


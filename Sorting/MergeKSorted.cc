/*
Comments :
Merge K sorted arrays each of size N . N is very large and may not be known.

Solution summary: maintain a heap of size K. At any given time there are K
elements in the heap one each from each of the K arrays. When intserting the K+1
the element in the heap evict the smallest element and get the next element from
the array to which this element belonged. So the heap elements must be a pair of
<array element, array index>
*/

#include <iostream>
#include <utility>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> element;

class Compare
{
 public:

  Compare(bool isMaxHeap=false) : m_maxHeap(isMaxHeap) {}

  bool operator()(const element& e1, const element& e2)
  {
    return m_maxHeap ? (e1.first < e2.first) : (e1.first > e2.first);
  }

 private:
  bool m_maxHeap;
};

void merge(const vector<vector<int> >& iarray)
{
  int K = iarray.size();
  bool isMaxHeap = iarray[0][0] > iarray[0][1];
  priority_queue<element, vector<element>, Compare> q((Compare(isMaxHeap)));
  vector<int> indices(K, 1);

  for (int i = 0; i < K; ++i)
    q.push(element(iarray[i][0], i));

  while (!q.empty())
  {
    cout << q.top().first << " ";
    int arrayIndex = q.top().second;
    q.pop();

    if (indices[arrayIndex] < iarray[arrayIndex].size()) {
      q.push(make_pair(iarray[arrayIndex][indices[arrayIndex]], arrayIndex));
      ++indices[arrayIndex];
    }
  }
}

int main(int argc, char** argv)
{
  vector<vector<int> > iarray = { {1,3,5, 7}, {2,4,6,8}, {0,9,10,11}};
  merge(iarray);
  return 0;
}


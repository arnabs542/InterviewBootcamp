/*
 * Implement a 2D iterator class. It will be initialized with an array of arrays, and should implement the following methods:

next(): returns the next element in the array of arrays. If there are no more elements, raise an exception.
has_next(): returns whether or not the iterator still has elements left.
For example, given the input [[1, 2], [3], [], [4, 5, 6]], calling next() repeatedly should output 1, 2, 3, 4, 5, 6.

Do not use flatten or otherwise clone the arrays. Some of the arrays can be empty.
*/

#include <iostream>
#include <vector>
#include <utility>
#include <stdexcept>

using namespace std;


class Iterator2D {
 public:
  Iterator2D(const vector<vector<int> >& arrays) : m_arrayRef(arrays),
                                                   m_arrayCount(arrays.size()),
                                                   m_index(0,0)
  {}

  int  next() {
    
    while (true) {
      if ((m_index.first == m_arrayCount-1) && (m_index.second == m_arrayRef[m_index.first].size()))
        throw range_error("End of 2D array");

      int val;
      if (m_index.second < m_arrayRef[m_index.first].size()) {
        val = m_arrayRef[m_index.first][m_index.second];
        ++m_index.second;
        return val;
      } else {
        ++m_index.first;
        m_index.second = 0;
      }
    }
    
  }

  bool hasNext() {
    return (m_index.second < m_arrayRef[m_index.first].size()) || ((m_index.first < m_arrayCount-1) && !((m_index.first+1) == m_arrayCount-1 && m_arrayRef[m_index.first+1].empty()));
  }

 private:
  const vector<vector<int> >& m_arrayRef;
  const size_t                m_arrayCount;
  pair<size_t, size_t>        m_index;
};


int main()
{
  vector<vector<int> > arrays = {{1,2}, {3}, {}, {4,5,6}, {7,8}, {9,10,11}, {}, {}};

  Iterator2D it(arrays);

  while (it.hasNext()) {
    cout << it.next() << " ";
  }
  cout << endl;

  return 0;

}

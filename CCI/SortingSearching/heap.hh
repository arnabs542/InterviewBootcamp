#ifndef __HEAP_HH__
#define __HEAP_HH__

#include <vector>
#include <cmath>

struct Heap
{
  Heap(std::vector<int>& array) : m_array(array), m_heapSize(array.size()-1) 
  {}

  void makeHeap();
  void maxHeapify(int index);
  void heapSort();

  int parent(int i) { return  std::ceil(i /2.0) - 1; }
  int left(int i)   { return  (i << 1) + 1;       }
  int right(int i)  { return  (i << 1) + 2;       }

  std::vector<int>& m_array;
  int               m_heapSize;
};

#endif

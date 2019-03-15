#include "Heap.hh"

void Heap::makeHeap()
{
  for (int i = m_array.size()/2; i >=0; --i)
    maxHeapify(i);
}


void Heap::maxHeapify(int index)
{
  while (index < m_heapSize)
  {
    int largest = index;
    if (left(index) <= m_heapSize && m_array[left(index)] > m_array[index])
      largest = left(index);
    if (right(index) <= m_heapSize && m_array[right(index)] > m_array[largest])
      largest = right(index);
    if (largest != index) {
      std::swap(m_array[index], m_array[largest]);
      index = largest;
    } else {
      break;
    }
  }
}

void Heap::heapSort()
{
  while (m_heapSize > 2)
  {
    std::swap(m_array[0], m_array[m_heapSize]);
    --m_heapSize;
    maxHeapify(0);
  }
}

/*
Comments :
*/

#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#include <deque>

using namespace std;

void slidingWindowMaxHeap(int windowSize, const vector<int>& input, vector<int>&
                      result)
{

  priority_queue<pair<int, int> > heap;

  for (int i = 0 ; i < windowSize; ++i)
    heap.push(make_pair(input[i], i));

  for (int i = windowSize; i < input.size(); ++i)
  {
    result.push_back(heap.top().first);
    while (heap.top().second <= i-windowSize)
      heap.pop();
    heap.push(make_pair(input[i], i));
  }

  result.push_back(heap.top().first);
}

// The idea is to have the largest element always in the front of the deque.
// Always insert new elements at the end, so the oldest elements are always at
// the front of the queue. The newer elements are at the back of the queue
// Before inserting each new element, check all elements at the back if the
// queue that are smaller, these are not required and can be removed
// Also check all old elements (front of queue) which are older than window size
// can also be removed from the front
void slidingWindowMaxDeque(int windowSize, const vector<int>& input,
                           vector<int>& result)
{
  deque<int> dq;

  for (int index = 0; index < windowSize; ++index)
  {
    while (!dq.empty() && input[dq.back()] <= input[index])
      dq.pop_back();
    dq.push_back(index);

  }

  for (int index = windowSize; index < input.size(); ++index)
  {
    result.push_back(input[dq.front()]);

    while(!dq.empty() && dq.front() <= index-windowSize)
      dq.pop_front();

    while (!dq.empty() && input[dq.back()] <= input[index])
      dq.pop_back();

    dq.push_back(index);
  }

  result.push_back(dq.front());
}


int main(int argc, char** argv)
{
  vector<int> res;
  vector<int> input = {1,3,-1,-3,5,3,6,7};
  //slidingWindowMaxHeap(3, input, res);
  slidingWindowMaxDeque(3, input, res);

  for (auto const& v : res)
    cout << v << " ";
  cout << endl;

  return 0;
}


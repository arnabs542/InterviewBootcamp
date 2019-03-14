/*
Comments :
Find a cycle in a singly linked list
*/

#include <iostream>

struct LL
{
  LL* next;
  int val;
};

using namespace std;

bool hasCycle(LL* head)
{
  LL* slow = head, *fast = head;

  while (fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
      return true;
  }

  return false;
}

// The node passed to this function is a node which is part of the cycle in the
// LL. One way of finding such a node is the point of intersection of slow and
// fast pointer in the hasCycle function
int cycleLength(LL* node)
{
  LL* ptr = node;
  int count = 0;

  while (ptr)
  {
    ptr = ptr->next;
    ++count;
    if (ptr == node)
      return count;
  }

  return -1;
}

int main(int argc, char** argv)
{
  return 0;
}


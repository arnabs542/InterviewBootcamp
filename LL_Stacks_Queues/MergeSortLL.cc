/*
Comments :
Merge sort a linked list in ascending order.

LL are suited for merge sort since we dont need extra O(n) space for sorting

Solution idea : call mergeSort on progrssively smaller LL till there is just one
element left in the list. Break a larger LL into two smaller LL before calling
merge sort of both recursively.
The merge operation merges the two sorted lists.
*/

#include <iostream>

using namespace std;

struct LinkedListNode
{
  int val;
  LinkedListNode* next;

  LinkedListNode(int v) : val(v), next(nullptr) {}
};

void addNode(LinkedListNode** head, LinkedListNode** tail, LinkedListNode* node)
{
  if (!(*head))
  {
    *head = node;
    *tail = node;
  }
  else
  {
    (*tail)->next = node;
    *tail = node;
  }
}

LinkedListNode* merge(LinkedListNode* left, LinkedListNode* right)
{
  // head and tail for the new list
  LinkedListNode* head = nullptr;
  LinkedListNode* tail = nullptr;

  // while there are elements in both lists
  while (left && right )
  {
    if (left->val > right->val)
    {
      addNode(&head, &tail, right);
      right = right->next;
    }
    else
    {
      addNode(&head, &tail, left);
      left = left->next;
    }
  }

  while (left)
  {
    addNode(&head, &tail, left);
    left = left->next;
  }

  while (right)
  {
    addNode(&head, &tail, right);
    right = right->next;
  }
  
  tail->next = nullptr;
  return head;
}

LinkedListNode* mergeSortList(LinkedListNode* pList)
{
  // single or 0 element list, nothing to sort
  if (!pList || !pList->next)
    return pList;

  // We are sure at this point that the list has atleast 2 elements, so
  // initialize slow and fast so that they point to atleast 2 different nodes
  LinkedListNode* prev = pList;
  LinkedListNode* slow = pList, *fast = pList->next;

  // use the slow/fast pointer to get to the middle of the list,
  // even if the list has just 2 elements and this loop does not run, we still
  // have slow and fast pointing to diff elements in the list
  while (fast && fast->next && fast->next->next)
  {
    prev = slow;
    slow = slow->next;
    fast = fast->next->next;
  }

  // If there are just 2 elements in the list
  if (slow == pList)
    slow = fast;

  // break the original list into two separate lists
  prev->next = nullptr;
  LinkedListNode* left = mergeSortList(pList);

  LinkedListNode* right = mergeSortList(slow);
  return merge(left, right);
}

void printList(LinkedListNode* head)
{
  while(head)
  {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}


int main(int argc, char** argv)
{
  LinkedListNode* head = new LinkedListNode(10);
  head->next = new LinkedListNode(9);
  head->next->next  = new LinkedListNode(8);
  printList(head);
  head = mergeSortList(head);
  printList(head);
  return 0;
}


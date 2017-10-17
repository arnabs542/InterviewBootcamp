/*
Comments :
Zip a linked list from its two ends.

e.g input 1->2->3->4->5->6
output :  1->6->2->5->3->4
*/

#include <iostream>

using namespace std;

class LinkedListNode 
{
 public:
  int             val;
  LinkedListNode* next;

  LinkedListNode(int node_value) 
  {
    val  = node_value;
    next = nullptr;
  }
};

LinkedListNode* _insert_into_singlylinkedlist(LinkedListNode** head,
                                              LinkedListNode** tail, 
                                              int              val) {
  if (*head == nullptr) {
    *head = new LinkedListNode(val);
    *tail = *head;
  } else {
    (*tail)->next = new LinkedListNode(val);
    *tail       = (*tail)->next;
  }

  return *tail;
}

void insert(LinkedListNode* insertPoint, LinkedListNode* prev, LinkedListNode**
            tail)
{
  LinkedListNode* nextNode = insertPoint->next;
  insertPoint->next = prev->next;
  prev->next->next = nextNode;

  *tail = prev;
  prev->next = nullptr;
}

LinkedListNode* reverse(LinkedListNode* head)
{
  LinkedListNode* curr = head->next;
  LinkedListNode* prev = head;

  while (curr)
  {
    LinkedListNode* tmp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = tmp;
  }

  head->next = nullptr;
  return prev;
}

LinkedListNode* zip(LinkedListNode* pList)
{
  // Use the fast / slow pointer trick to find the middle of the list
  LinkedListNode* slow = pList, * fast = pList;

  // after this loop, the slow pointer will point to the middle of the list
  while (fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;
  }

  if (slow == fast)
    return pList;

  // break the linked list at this point, head is the pointer to the start of 2nd half
  // list
  LinkedListNode* list = reverse(slow->next);
  slow->next = nullptr;

  // use the fast pointer (unused after this) to save the pointer to the head of
  // original list
  fast = pList;

  // now zip the two lists together
  while(list)
  {
    LinkedListNode* tmp = pList->next;
    pList->next = list;
    list = list->next;
    pList->next->next = tmp;
    pList = pList->next->next;
  }

  return fast;
}

void printList(LinkedListNode* head)
{
  while (head) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}

int main(int argc, char** argv)
{
  LinkedListNode* head = nullptr;
  LinkedListNode* tail = nullptr;
  _insert_into_singlylinkedlist(&head, &tail, 1);
  _insert_into_singlylinkedlist(&head, &tail, 2);
  _insert_into_singlylinkedlist(&head, &tail, 3);
  _insert_into_singlylinkedlist(&head, &tail, 4);
  _insert_into_singlylinkedlist(&head, &tail, 5);
  _insert_into_singlylinkedlist(&head, &tail, 6);
  printList(head);
  LinkedListNode* h1 = zip(head);
  printList(h1);
  return 0;
}

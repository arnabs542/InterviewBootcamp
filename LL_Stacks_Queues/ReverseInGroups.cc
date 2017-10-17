/*
Comments :
Given a linked list, write a function to reverse every k nodes ( where k is an
input to the function)
Example
Input : 1->2->3->4->5->6->7->8->NULL and k=3
Output: 3->2->1->6->5->4->8->7->NULL

Solution summary:
Code up function to reverse a LL using two pointers current and prev. Only, in
this, just reverse k nodes. The function returns the new head of the list.
Recursively call the function on k+1th node in original LL. 
Link together the tail of current reversed LL with the head of the reversed LL
starting at k+1th node.
*/

#include <iostream>

using namespace std;

class LinkedListNode {
 public:
  int             val;
  LinkedListNode* next;

  LinkedListNode(int node_value) {
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

void printList(LinkedListNode* head)
{
  while (head) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}

LinkedListNode* reverseInGroups(LinkedListNode* pList, int k)
{
  LinkedListNode* current = pList;
  LinkedListNode* prev = nullptr;

  int count = k;
  while (current && count--)
  {
    LinkedListNode* nextNode = current->next;
    current->next = prev;
    prev = current;
    current = nextNode;
  }

  if (current)
    // Link the tail of this list to the head of the next list
    pList->next = reverseInGroups(current, k);

  // return the head of this list
  return prev;
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
  _insert_into_singlylinkedlist(&head, &tail, 7);
  _insert_into_singlylinkedlist(&head, &tail, 8);
  printList(head);
  head = reverseInGroups(head,5);
  printList(head);
  return 0;
}

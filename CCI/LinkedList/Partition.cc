extern "C" {
#include "LinkedList.h"
}

#include <iostream>

void partition(Node** head, int val)
{
  Node* newHead = *head;
  Node* tail = *head;
  Node* curr = *head;

  while(curr)
  {
    Node* next = curr->next;

    if (curr->val < val)
    {
      curr->next = newHead;
      newHead = curr;
    }
    else
    {
      tail->next = curr;
      tail = curr;
    }
    curr = next;
  }

  tail->next = nullptr;
  *head = newHead;
}

void printList(Node* head)
{
  while(head)
  {
    std::cout << head->val << ",";
    head = head->next;
  }

  std::cout << std::endl;
}

int main()
{
  Node* head = nullptr;
  
  addToList(&head, 1);
  addToList(&head, 2);
  addToList(&head, 10);
  addToList(&head, 5);
  addToList(&head, 8);
  addToList(&head, 5);
  addToList(&head, 3);

  printList(head);
  partition(&head, 3);
  printList(head);

  return 0;
}

extern "C" {
#include "LinkedList.h"
}

#include <iostream>

void removeDup(LinkedList* list)
{
  int table[100] = {0};

  Node* prev = nullptr;
  Node* curr = list->head;

  while (curr)
  {
    Node* toDelete = nullptr;

    if (table[curr->val])
    {
      prev->next = curr->next;
      curr = curr->next;
      toDelete = curr;
    }
    else
    {
      table[curr->val] = 1;
      prev = curr;
      curr = curr->next;
    }

    if (toDelete)
      delete toDelete;
  }
}

void printList(Node* head)
{
  while (head) {
    std::cout << head->val << ", ";
    head = head->next;
  }
  std::cout << std::endl;
}

void addToList(Node** head, int val)
{
  if (!(*head))
  {
    *head = new Node(val);
    return;
  }

  Node* curr = *head;
  while(curr && curr->next)
  {
    curr = curr->next;
  }
  curr->next = new Node(val);
}

int main()
{
  LinkedList list;
  addToList(&(list.head), 1);
  addToList(&(list.head), 1);
  addToList(&(list.head), 1);
  addToList(&(list.head), 1);
  addToList(&(list.head), 1);
  addToList(&(list.head), 1);
  addToList(&(list.head), 1);

 removeDup(&list);

 printList(list.head);

  return 0;
}

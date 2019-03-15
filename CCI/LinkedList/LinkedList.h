#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

struct Node
{
  Node(int v): val(v), next(nullptr) {}

  int   val;
  Node* next;
};

struct LinkedList
{
  LinkedList() : head(nullptr) {}
  Node* head;
};


void addToList(Node** head, int val)
{
  Node* node = new Node(val);
  if (!(*head)) {
    *head = node;
    return;
  }

  node->next = *head;
  *head = node;
}

#endif

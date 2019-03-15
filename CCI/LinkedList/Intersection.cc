extern "C" {
#include "LinkedList.h"
}

#include <iostream>

Node* intersect(Node* head1, Node* head2)
{
  if (!head1 && !head2)
    return nullptr;

  if (head1 && head2) {
    Node* res = intersect(head1->next, head2->next);
    if (res && head1 != head2)
      return res;
  }

  if (head1) {
    Node* res = intersect(head1->next, head2);
    if (res && head1 != head2)
      return res;
  }

  if (head2) {
    Node* res = intersect(head1, head2->next);
    if (res && head1 != head2)
      return res;
  }

  if (head1 == head2)
    return head1;
}



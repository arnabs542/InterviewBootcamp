/*
Comments :
In a given singly linked list of length N, swap Kth node from the beginning with
the Kth node from the end. We're not just swapping the contents of the nodes,
we;re swapping the nodes themselves.
1 <= K <= N
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

LinkedListNode* swapNodes(LinkedListNode* pList, LinkedListNode* begin,
                          LinkedListNode* beginPrev, LinkedListNode* end,
                          LinkedListNode* endPrev)
{
  if (begin == end)
    return pList;

  // The first element needs replacement
  if (begin == pList)
  {
    LinkedListNode* beginNext = begin->next;
    LinkedListNode* endNext = end->next;
    endPrev->next = begin;
    endPrev->next->next = endNext;
    end->next = beginNext;
    return end;
  }

  if (begin->next == end)
  {
    LinkedListNode* endNext = end->next;
    beginPrev->next = end;
    end->next = begin;
    end->next->next = endNext;
    return pList;
  }

  if (end->next == begin)
  {
    LinkedListNode* beginNext = begin->next;
    endPrev->next = begin;
    begin->next = end;
    begin->next->next = beginNext;
    return pList;
  }

  LinkedListNode* endNext = end->next;
  beginPrev->next = end;
  beginPrev->next->next = begin->next;
  endPrev->next = begin;
  endPrev->next->next = endNext;
  return pList;
}

LinkedListNode* swapNodes(LinkedListNode* pList, int iK) {
  LinkedListNode* begin = pList;
  LinkedListNode* beginPrev = pList;

  // initialize the begin pointer
  for (int i = iK-1; i > 0;  --i) {
    beginPrev = begin;
    begin = begin->next;
  }


  // find the node in the LL which is K nodes from the end.
  // for this start with two nodes, which have a relative distance of K nodes.
  // Increment both by one node till the the node which is K nodes ahead reaches
  // the end of the list, then the other node will be K nodes from the end
  LinkedListNode* node = begin;
  LinkedListNode* endPrev = pList;
  LinkedListNode* end = pList;

  while(node && node->next)
  {
    node = node->next;
    endPrev = end;
    end = end->next;
  }

  return swapNodes(pList, begin, beginPrev, end, endPrev);
}


int main(int argc, char** argv)
{

  LinkedListNode* head = nullptr;
  LinkedListNode* tail = nullptr;
  _insert_into_singlylinkedlist(&head, &tail, 11);
  _insert_into_singlylinkedlist(&head, &tail, 2);
  _insert_into_singlylinkedlist(&head, &tail, 4);
  _insert_into_singlylinkedlist(&head, &tail, 1);
  //_insert_into_singlylinkedlist(&head, &tail, 7);
  //_insert_into_singlylinkedlist(&head, &tail, 0);
  printList(head);
  head = swapNodes(head, 3);
  printList(head);
  return 0;
}


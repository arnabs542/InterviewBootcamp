/*
Comments :
Given a linked list split it into two such that every other node gets into the
new list. For lists with odd number of nodes , first one should be longer. For
example : an input list {a,b,c,d,e,f,g}  results in {a,c,e,g} and  {b,d,f}
*/

#include <iostream>

using namespace std;

void printList(LinkedListNode* node)
{
  while (node)
  {
    cout << node->val ;
    node = node->next;
  }
  cout << endl;
}

void alternativeSplit(LinkedListNode* pList) {
  LinkedListNode* head = nullptr, *tail = nullptr;
  LinkedListNode* prev = pList;
  bool count = false;
  LinkedListNode* old = pList;

  while (pList) {
    if (!count) {  // remains in old list
      prev = pList;
      pList = pList->next;
    }
    else {
      prev->next = pList->next;

      if (!head) {
        head = tail = pList;
      } else {
        tail->next = pList;
        tail = pList;
      }
      pList->next = nullptr;
      pList = prev->next;
    }

    count = count ? false : true;
  }

  printList(old);
  printList(head);
}

int main(int argc, char** argv)
{
  return 0;
}


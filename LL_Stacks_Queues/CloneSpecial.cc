/*
Comments :
You are given a double link list with one pointer of each node pointing in to
the next node just like a single link list. The second pointer can however point
to any node in the list and not just the previous node. 
Now write a program in with O(n) time to duplicate this list. That is write a
program that will duplicate this list.
Let us call the second pointer an arbit pointer.
Do this with constant extra memory.
*/

#include <iostream>

using namespace std;

template <typename T>
struct Node {
  T val;
  Node* next;
  Node* arbit;

  Node(const T& v) {
    val = v;
    next = nullptr;
    arbit = nullptr;
  }
};

template <typename T>
struct LL {
  Node<T>* head;
  Node<T>* tail;

  LL() {
    head = nullptr;
    tail = nullptr;
  }

  void add(const T& v)
  {
    Node<T> * node = new Node<T>(v);

    if (tail ) {
      tail ->next = node;
    }
    tail = node;

    if (!head)
      head = node;
  }
};


template<typename T>
LL<T>* clone(LL<T>* l1) {
  LL<T>* l2 = new LL<T>();

  Node<T>* prev = nullptr;
  Node<T>* ptr = l1->head;

  while (ptr) {
    Node<T>* n = new Node<T>(ptr->val);
    n->arbit = ptr->arbit;
    ptr->arbit = n;
    
    if(!prev) {
      l2->head = n;
    } else {
      prev->next = n;
    }
    prev = n;
    ptr = ptr->next;
  }
  l2->tail = prev;

  ptr = l2->head;
  while (ptr) {
    ptr->arbit = ptr->arbit->arbit;
    ptr = ptr->next;
  }

  return l2;
}

template <typename T>
void printList(LL<T>* list)
{
  Node<T>* ptr = list->head;
  cout << "printing list " << endl;
  while (ptr) {
    cout << ptr << " " << ptr->val << "  " << ptr->arbit << endl;
    ptr = ptr->next;
  }
}

int main(int argc, char** argv)
{
  LL<int> list;

  list.add(1); list.add(2); list.add(3); list.add(4); list.add(5);
  list.head->arbit = list.head->next->next;
  list.head->next->arbit = list.head;
  list.head->next->next->arbit = list.tail;
  list.head->next->next->next->arbit = list.head->next->next;
  list.tail->arbit = list.head->next;

  printList(&list);

  LL<int> *newList = clone(&list);
  printList(newList);

  return 0;
}


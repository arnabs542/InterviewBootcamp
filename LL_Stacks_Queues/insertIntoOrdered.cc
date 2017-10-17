/*
Comments :
Insert a node containing integer value into an ordered linked list
*/

#include <iostream>

using namespace std;

struct Node
{
  Node(int value) : val(value), next(nullptr) {}

  int val;
  Node* next;
};

void insert(Node** list, int value)
{
  Node* prev = *list;
  Node* curr = *list;

  Node* newNode = new Node(value);

  while (curr && curr->val < value)
  {
    prev = curr;
    curr = curr->next;
  }

  if (curr == prev)
  {
    newNode->next = *list;
    *list = newNode;
  }
  else
  {
    prev->next = newNode;
    newNode->next = curr;
  
  }
}

void printList(Node* list)
{
  while(list) {
    cout << list->val << " ";
    list = list->next;
  }

  cout << endl;
}

int main(int argc, char** argv)
{
  Node* list = nullptr;
  insert(&list, 10);
  insert(&list, 9);
  insert(&list, 8);
  insert(&list, 7);
  insert(&list, 6);
  insert(&list, 11);

  printList(list);
  return 0;
}


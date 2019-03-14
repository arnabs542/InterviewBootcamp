/*
Comments :
Reverse a singly linked list
*/

#include <iostream>

using namespace std;

struct LL
{
  int val;
  LL* next;
};

void reverse(LL** head)
{
  LL* prev = nullptr, curr = *head;

  while (curr)
  {
    LL* tmp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = tmp;
  }

  *head = prev;
}

int main(int argc, char** argv)
{
  return 0;
}


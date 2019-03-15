extern "C" {
#include "LinkedList.h"
}

#include <iostream>
#include <queue>
#include <cassert>

using namespace std;


bool isPalindrome(Node* head, queue<int>& st)
{
  if (!head)
    return true;

  st.push(head->val);

  if (!isPalindrome(head->next, st))
    return false;

  auto val = st.front(); st.pop();

  return head->val == val;
}


int main()
{
  Node *head1 = nullptr, *head2 = nullptr, *head3 = nullptr;
  queue<int> q;

  addToList(&head1, 1);
  addToList(&head1, 3);
  addToList(&head1, 1);
  assert(isPalindrome(head1, q) == true);

  addToList(&head2, 3);
  addToList(&head2, 5);
  addToList(&head2, 7);
  addToList(&head2, 3);
  while (!q.empty())
    q.pop();
  assert(isPalindrome(head2, q) == false);

  addToList(&head3, 1);
  while (!q.empty())
    q.pop();
  assert(isPalindrome(head3, q) == true);

  return 0;
}

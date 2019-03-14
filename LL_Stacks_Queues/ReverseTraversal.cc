/* Populate previous pointers for a singly linked list
 */

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  ListNode(int val) : val(val), next(nullptr), prev(nullptr) {}

  int val;
  ListNode* next;
  ListNode* prev;
};

ListNode* head = nullptr, *tail = nullptr;

void reverseTraversal(ListNode* head)
{
  ListNode* prev = nullptr;
  ListNode* curr = head;

  while (curr) {
    curr->prev = prev;
    prev = curr;
    curr = curr->next;
  }
}

void printList(ListNode* head)
{
  while(head) {
    cout << head->val << ",";
    head = head->next;
  }
  cout << endl;
}

void printListReverse(ListNode* tail)
{
  while (tail) {
    cout << tail->val << ",";
    tail = tail->prev;
  }
  cout << endl;
}

int main()
{
  ListNode* prev = nullptr;

  vector<int> array = {1,2,3,4,5,6,7,8};
  for (auto a: array) {
    ListNode* node = new ListNode(a);

    if (!head) {
      head = node;
    }
    if (prev)
      prev->next = node;
    prev = node;
  }

  tail = prev;
  printList(head);
  reverseTraversal(head);
  printListReverse(tail);

  return 0;
}





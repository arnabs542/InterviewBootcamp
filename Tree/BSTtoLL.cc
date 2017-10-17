/*
Comments :
*/
#include <iostream>
#include <stack>

using namespace std;

// Tree Node
struct Node
{
  Node(int v) : val(v), left(nullptr), right(nullptr) {}

  int val;
  Node* left;
  Node* right;
};

// Linked list information
struct LL
{
  Node* head;
  Node* tail;
};

// Append two sorted linked lists a and b. a comes before b
LL append(LL& a, LL& b)
{
  LL merged;

  if (a.tail)
    a.tail->right = b.head;
  if (b.head)
    b.head->left  = a.tail;
  merged.head = a.head ? a.head : b.head;
  merged.tail = b.tail ? b.tail : a.tail;
  return {merged.head, merged.tail};
}

LL BSTtoLLHelper(Node* root)
{
  if (!root)
    return {nullptr, nullptr};

  LL leftList =  BSTtoLLHelper(root->left);
  LL rightList = BSTtoLLHelper(root->right);

  LL rootList;
  rootList.head = rootList.tail = root;
  LL list1 = append(leftList, rootList);
  LL list2 = append(list1, rightList);
  return list2;
}

// Print the linked list
void printList(const LL& list)
{
  Node* node = list.head;

  while(node) {
    cout << node->val << " ";
    node = node->right;
  }
  cout << endl;
}

void BSTtoLL(Node* root)
{
  LL list = BSTtoLLHelper(root);
  printList(list);
}

int main(int argc, char** argv)
{
  Node* root = new Node(25);
  root->left = new Node(15);
  root->right = new Node(45);
  root->left->left = new Node(5);
  root->left->right = new Node(20);
  root->right->left = new Node(30);
  root->right->right = new Node(50);
  BSTtoLL(root);
  return 0;
} 

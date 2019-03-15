#include <iostream>
#include <stdlib.h>
#include <queue>


struct Node
{
  Node(int v): val(v), size(1), left(nullptr), right(nullptr) {}

  int    val;
  size_t size;
  Node*  left;
  Node*  right;
};


class Tree
{
 public:
  Tree() : root(nullptr), count(0) {}

  void  insert(int val);
  Node* find(int val);
  int   getRandom();
  void  printTree();

 private:
  Node*   root;
  size_t  count;
};


void Tree::insert(int val)
{
  ++count;

  if (!root)
  {
    root = new Node(val);
    return;
  }


  Node* curr = root;
  Node* prev = root;

  while (curr)
  {
    ++curr->size;

    if (val > curr->val)
    {
      prev = curr;
      curr = curr->right;
    }
    else
    {
      prev = curr;
      curr = curr->left;
    }
  }

  if (val > prev->val)
    prev->right = new Node(val);
  else
    prev->left = new Node(val);
}

Node* Tree::find(int val)
{
  Node* curr = root;

  while (curr)
  {
    if (val == curr->val)
      return curr;

    if (val > curr->val)
      curr = curr->right;
    else
      curr = curr->left;
  }

  return nullptr;
}

int Tree::getRandom()
{
  int randomVal = rand() % count + 1;

  std::cout << "Random Number: " << randomVal << std::endl;

  Node* curr = root;

  while (randomVal)
  {
    int leftCount = curr->left ? curr->left->size: 0;
    if (randomVal - leftCount == 1)
      break;

    if (curr->left && (randomVal <= curr->left->size)) {
      curr = curr->left;
    }
    else {
      randomVal -= (leftCount + 1);
      curr = curr->right;
    }
  }

  assert(curr != nullptr);

  return curr->val;
}


void Tree::printTree()
{
  if (count == 0)
    return;

  int count = 1;
  std::queue<Node*> q;
  q.push(root);

  while (!q.empty())
  {
    int newCount = 0;
    while (count)
    {
      Node* n = q.front(); q.pop(); --count;

      std::cout << n->val << ":" << n->size << " ";

      if (n->left) {
        q.push(n->left);
        ++newCount;
      }
      if (n->right) {
        q.push(n->right);
        ++newCount;
      }
    }
    std::cout << std::endl;
    count = newCount;
  }
}

int main()
{
  Tree tree;

  tree.insert(20);
  tree.insert(10);
  tree.insert(30);
  tree.insert(5);
  tree.insert(15);
  tree.insert(7);
  tree.insert(14);
  tree.insert(25);
  tree.insert(21);
  tree.insert(26);
  tree.insert(35);

  tree.printTree();
  std::cout << tree.getRandom() << std::endl;
  std::cout << tree.getRandom() << std::endl;
  std::cout << tree.getRandom() << std::endl;
  std::cout << tree.getRandom() << std::endl;
  std::cout << tree.getRandom() << std::endl;
  std::cout << tree.getRandom() << std::endl;
  std::cout << tree.getRandom() << std::endl;
  std::cout << tree.getRandom() << std::endl;
  std::cout << tree.getRandom() << std::endl;
  std::cout << tree.getRandom() << std::endl;

  return 0;
}

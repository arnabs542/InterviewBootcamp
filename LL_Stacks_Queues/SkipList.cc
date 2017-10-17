/*
Comments :
Implement a simple skip list
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

class SkipList
{
  struct Node
  {
    int           val;
    vector<Node*> next;

    Node(int v, int level) : val(v), next(level +1, nullptr) {}
  };

  Node*  m_head;
  int    m_levels;

  void freeMemory();

 public:
  void insert(int val);
  bool erase(int val);
  bool exists(int val);
  void enumerate();

  SkipList():m_head(nullptr), m_levels(1) 
  {
    m_head = new Node(numeric_limits<int>::min(), 32);
  }
 
  ~SkipList() { }
};

void SkipList::insert(int val)
{
  // find the number of levels this node will have
  int level = 0;
  for (int randomVal = rand(); ((randomVal & 0x1) == 1) && level <= 32; randomVal >>= 1)
  {
    ++level;
  }

  cout << "level: " << level << endl;
  if (level >= m_levels) 
    m_levels = level+1;

  // create node
  Node *newNode = new Node(val, level);
  // actually insert the node starting from level 0
  Node* curr = m_head;

  // start from the highest level and move down the list levels. This will
  // ensure least amount of lookup for the position to insert the node in.
  for (int l = m_levels-1; l >= 0; --l)
  {

    while(curr->next[l] != nullptr && curr->next[l]->val < val)
    {
      curr = curr->next[l];
    }

    if (l <= level)
      newNode->next[l] = curr->next[l]; curr->next[l] = newNode;
  }

  cout << "Successfully inserted key " << val << endl;
}

bool SkipList::erase(int val)
{
  bool found = false;
  Node* toDelete = nullptr;

  Node* curr = m_head;
  for (int level = m_levels-1; level >= 0; --level)
  {
    while (curr->next[level] && curr->next[level]->val < val)
    {
      curr = curr->next[level];
    }

    if (curr->next[level] && curr->next[level]->val == val)
    {
      found = true;
      toDelete = curr->next[level];
      curr->next[level] = curr->next[level]->next[level];
    }
  }

  if (found && toDelete)
    delete toDelete;

  cout << "Successfully deleted key: " << val << endl;
  return found;
}

bool SkipList::exists(int val)
{
  Node* curr = m_head;
  for (int level = m_levels-1; level >= 0; --level)
  {
    while (curr->next[level] && curr->next[level]->val < val)
      curr = curr->next[level];

    if (curr->next[level] && curr->next[level]->val == val)
      return true;
  }

  return false;
}

void SkipList::enumerate()
{
  cout << " Skip List " << endl;
  for (int level = m_levels-1; level >=0; --level)
  {
    cout << "Level " << level << ": ";
    Node* curr = m_head->next[level];
    while(curr)
    {
      cout << curr->val << " ";
      curr = curr->next[level];
    }
    cout << endl;
  }
}

int main(int argc, char** argv)
{
  srand(time(0));
  SkipList sl;
  sl.insert(5);
  cout << sl.exists(5) << endl;
  sl.insert(4);
  sl.enumerate();
  return 0;
}


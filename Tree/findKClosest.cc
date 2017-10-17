/*
Comments :
Find the K closest values to a target in a BST.
Solution summary : inorder traversal to get the sorted list = O(N)
Then find the cross-over point - point in the list where values start getting
greater than the target. The K closest values are clustered around this
cross-over point and can be got using two pointers to the list.
*/

#include <iostream>
#include <priority_queue>
#include <utility>

using namespace std;

// Tree Node
struct Node
{
  Node(int v) : val(v), left(nullptr), right(nullptr) {}

  int val;
  Node* left;
  Node* right;
};

bool operator()(const pair<int, int>& p1, const pair<int, int>& p2)
{
  return p1.first > p2.first;
}

typedef priority_queue<pair<int, int>, greater > maxHeap;


int main(int argc, char** argv)
{
  return 0;
}


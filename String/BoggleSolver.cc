/*
Comments :
Given a dictionary and a method to do lookup in a dictionary and a MxN board
where every cell has one character. Find all possible words that can be formed
bya sequence of adjacent characters.Note that a word should not have multiple
instances of the same cell
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <utility>
#include <tuple>

using namespace std;

struct TrieNode
{
  TrieNode() : isLeaf(false) {}

  bool isLeaf;
  unordered_map<string, TrieNode*> children;
};

TrieNode* constructTrie(const vector<string>& dictionaryList)
{
  TrieNode* root = new TrieNode();

  for (auto const& word : dictionaryList)
  {
    TrieNode* node = root;
    for (auto ch : word)
    {
      string strChar = string(1,ch);
      auto childIt = node->children.find(strChar);
      TrieNode* child = nullptr;
      if (childIt == node->children.end()) {
        // Need to create a new child node
        child = new TrieNode();
        node->children[strChar] = child;
      }
      else {
        //  child node exists
        child = childIt->second;
      }

      node = child;
    }
    node->isLeaf = true;
  }

  return root;
}

vector<pair<int, int> > getNeighbors(int i, int j, int maxRow, int maxCol)
{
  static const vector<pair<int, int> > NeighborOffsets = {
                                       {-1,-1}, {-1,0}, {-1,1}, 
                                       {0,-1},           {0,1},  
                                       {1,-1},  {1,0},   {1,1}
                                     };

  vector<pair<int, int> > neighbors;

  for (auto const& off : NeighborOffsets)
  {
    int new_i = i + off.first;
    int new_j = j + off.second;
    if ((new_i >= 0) && (new_i < maxRow) &&
        (new_j >=0) && (new_j < maxCol))
      neighbors.push_back(make_pair(new_i, new_j));
  }
  return neighbors;
}

void dfs(int i, int j, const vector<vector<string> >& board, 
         TrieNode* root, vector<string>& result)
{
  if (root->children.find(board[i][j]) == root->children.end())
    return;

  set<pair<int, int> > visited;
  typedef tuple<int, int, TrieNode*, string> QueueNode;

  queue<QueueNode> q;
  q.push(QueueNode(i, j, root->children[board[i][j]], board[i][j]));

  int maxRow = board.size();
  int maxCol = board[0].size();

  while (!q.empty())
  {
    QueueNode& node = q.front();
    if (get<2>(node)->isLeaf)
      result.push_back(get<3>(node));

    visited.insert(make_pair(get<0>(node), get<1>(node)));

    for (auto const& n : getNeighbors(get<0>(node), get<1>(node), maxRow,
                                      maxCol))
    {
      int new_i = n.first;
      int new_j = n.second;
      TrieNode* trieNode = get<2>(node);

      if (visited.find(make_pair(new_i, new_j)) == visited.end() &&
          trieNode->children.find(board[new_i][new_j]) !=
          trieNode->children.end())
        q.push(QueueNode(new_i, new_j,
                         trieNode->children[board[new_i][new_j]],
                         get<3>(node) + board[new_i][new_j]));
    }
    q.pop();
  }
}

vector<string> findWords(const vector<string>& dictionaryList,
                         const vector<vector<string> >& board)
{
  TrieNode* root = constructTrie(dictionaryList);
  vector<string> result;

  for (int i = 0; i < board.size(); ++i)
  {
    for (int j=0; j < board[0].size(); ++j)
    {
      dfs(i, j, board, root, result);
    }
  }

  return result;
}

int main(int argc, char** argv)
{
  vector<string> dictionary = {"GEEKS", "FOR", "QUIZ", "GO"};
  vector<vector<string> > boggle = {{"G", "I", "Z"},
                                    {"U", "E", "K"},
                                    {"Q", "S", "E"}
                                   };

  for (auto const& word : findWords(dictionary, boggle))
    cout << word << " ";
  cout << endl;
      
  return 0;
}


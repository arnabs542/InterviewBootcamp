#include <vector>
#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;


typedef vector<vector<int> > Grid;
typedef pair<int, int>       Position;
typedef vector<Position>     Path;

vector<Position> increments = {{1,0}, {0,1}};

vector<Position> getNext(Position& pos, Grid& g, int r, int c)
{
  vector<Position> neigh;

  for (auto inc: increments)
  {
    int i = pos.first + inc.first;
    int j = pos.second + inc.second;
    if ( i <= r && j <= c && g[i][j] != -1) {
      neigh.push_back(Position(i,j));
    }
  }

  return neigh;

}

struct pair_hash {
  template <class T1, class T2>
  std::size_t operator () (const std::pair<T1,T2> &p) const {
    auto h1 = std::hash<T1>{}(p.first);
    auto h2 = std::hash<T2>{}(p.second);

    // Mainly for demonstration purposes, i.e. works but is overly simple
    // In the real world, use sth. like boost.hash_combine
    return h1 ^ h2;  
  }
};

Path findPath(Grid& g)
{
  int r = g.size()-1;
  int c = g[0].size()-1;

  unordered_map<Position, Position, pair_hash> visited;
  stack<Position> st;
  Position stop = {r,c};

  st.push(Position(0,0));
  visited.emplace(Position(0,0), Position(-1,-1));
  bool done = false;

  while (!st.empty() && !done)
  {
    Position pos = st.top(); st.pop();

    for (auto p: getNext(pos, g, r, c))
    {
      if (visited.count(p))
        continue;
      visited[p] = pos;

      if (p == stop)
      {
        done = true;
        break;
      }

      st.push(p);

    }
  }

  Path res;
  if (!done)
    return res;

  while (!st.empty())
    st.pop();

  auto pos = Position(r,c);

  stop = Position(-1,-1);
 
  st.push(pos);
  while (pos != stop)
  {
    pos = visited[pos];

    if (pos != stop)
      st.push(pos);
  }

  while (!st.empty())
  {
    res.push_back(st.top());
    pos = visited[st.top()];
    st.pop();
  }

  return res;
}

int main()
{
  Grid g = {{1,1,1}, {1,1,1,}, {1,1,1}};

  for (auto pos: findPath(g))
    cout << "{" << pos.first << "," << pos.second << "}" << endl;

  return 0;
}

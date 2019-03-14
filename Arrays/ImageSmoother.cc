/*
Comments :
*/


#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<pair<int, int> > getNeighbors(int i, int j, const vector<vector<int> >& array)
    {
        vector<pair<int ,int> > neighbors = {{-1,-1}, {-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        
        const int Row = array.size(); const int Col = array[0].size();

        vector<pair<int, int> > adj;
        for (auto const p : neighbors)
        {
            int i1 = p.first + i;
            int j1 = p.second + j;
            if (i1 >= 0 && i1 < Row && j1 >= 0 && j1 < Col)
                adj.push_back(make_pair(i1, j1));
        }
        
        return adj;
        
    }
    vector<vector<int> > imageSmoother(vector<vector<int>>& M) {
        
        vector<vector<int> > result(M.size(), vector<int>(M[0].size(), 0));
        
        for (int i = 0; i < M.size(); ++i)
        {
            for (int j = 0; j < M[0].size(); ++j)
            {
                int sum = M[i][j];
                vector<pair<int, int> > neighbors = getNeighbors(i,j,M);
                for (auto const &n : neighbors)
                {
                    sum += M[n.first][n.second];
                }
                result[i][j] = sum/(neighbors.size()+1);
                        
            }
        }
        
        return result;
        
        
        
        
    }

int main(int argc, char** argv)
{
  vector<vector<int> > a = {{1,1,1}, {1,0,1}, {1,1,1}};
  vector<vector<int> > b = imageSmoother(a);

  for (auto const & v : b) {
    for (auto const& v1 : v) {
      cout << v1 << " ";
    }
    cout << endl;
  }
  return 0;
}


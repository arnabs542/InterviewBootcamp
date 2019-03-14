/*
Comments :
You're given three strings A,B and I . Write a function that checks if I is an
interleaving of A and B.String I is said to be an interleaving of A and B, if it
contains all characters of A and B and order of all characters in individual
strings is preserved.

Solution summary: Assume function int(i,j,k) is called with indices i, j, k for
string A, B and I. Then this must be true:

int(i,j,k) = (A[i] == I[i+j] && int(i+1, j, k+1)) ||
             (B[j] == I[i+j] && int(i, j+1, k+1))

Note that the index into string I is the sum of i and j.
Also, an optimization is to return false if len(I) != len(A) + len(B)

dp table[i][j] is true if substring of I of length (i+j) is an interleaving of
substring of A of len i and substring of B of len j. table[0][0] is then by
defintion true since empty substring is an interleaving of two empty substrings.
And then solution is in table[A.len()][B.len()].
*/

#include <iostream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

bool isInterleaving(const string& a, const string& b, const string& c)
{
  if (c.size() != a.size() + b.size())
    return false;
  
  if (a.empty())
  {
    if (b == c)
      return true;
    return false;
  }

  if (b.empty())
  {
    if (a==c)
      return true;
    return false;
  }
  
  vector<vector<bool> > table(a.size()+1, vector<bool>(b.size()+1, 0));
 
  // Initialize 
  table[0][0] = true;

  for (int j = 1; j <= b.size(); ++j)
    table[0][j] = (b[j-1] == c[j-1] && table[0][j-1]);
  for (int i = 1; i <= a.size(); ++i)
    table[i][0] = (a[i-1]== c[i-1] && table[i-1][0]);

  for (int i = 1; i <= a.size(); ++i)
  {
    for (int j=1; j <= b.size(); ++j)
    {
      table[i][j] = (a[i-1] == c[i+j-1] && table[i-1][j]) ||
                    (b[j-1] == c[i+j-1] && table[i][j-1]);
    }
  }

  return table[a.size()][b.size()];
}

int main(int argc, char** argv)
{
  typedef tuple<string, string, string, bool> testTuple;
  vector<testTuple> tests = { {"1234", "123", "123", 0},
                              {"112233","123", "123",1},
                              {"123456", "123456", "", 1},
                              {"123456", "", "123456", 1},
                              {"12345678","1234", "5678", 1},
                              {"12345678", "1233","5678",0}
                            };

  for (auto const& test : tests)
  {
    if (isInterleaving(get<1>(test), get<2>(test), get<0>(test)) == get<3>(test))
      cout << "OK" << endl;
    else
      cout << "NOT OK:" << get<0>(test) << " " << get<1>(test) << " " << get<2>(test) << endl;
  }

  return 0;
}


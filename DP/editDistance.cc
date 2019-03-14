/*
Comments :
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int EditDistanceRec(const string& s1, const string& s2, int i , int j)
{
  if (i == s1.size())
    return s2.size() - j;

  if (j == s2.size())
    return s1.size() - i;

  if (s1[i] == s2[j])
    return EditDistanceRec(s1, s2, i+1, j+1);

  return 1 + min(EditDistanceRec(s1, s2, i+1, j),           // delete
                 min(EditDistanceRec(s1, s2, i, j+1),       // insert
                     EditDistanceRec(s1, s2, i+1, j+1)));   // replace
}

int EditDistanceMemoized(const string& s1, const string& s2, int i, int j,
                         vector<vector<int> >& dpTable)
{
  if (dpTable[i][j] != -1)
    return dpTable[i][j];

  if (i == s1.size())
    return dpTable[i][j] = s2.size() - j;

  if (j == s2.size())
    return dpTable[i][j] = s1.size() - i;

  if (s1[i] == s2[j])
    return dpTable[i][j] = EditDistanceMemoized(s1, s2, i+1, j+1, dpTable);

  return dpTable[i][j] = 1 + min(EditDistanceMemoized(s1, s2, i+1, j, dpTable),           // delete
                 min(EditDistanceMemoized(s1, s2, i, j+1, dpTable),       // insert
                     EditDistanceMemoized(s1, s2, i+1, j+1, dpTable)));   // replace
}

int EditDistanceDP(const string& s1, const string& s2)
{
  vector<vector<int> > table(s1.size() + 1, vector<int>(s2.size()+1, -1));

  table[0][0] = 0;
  table[1][0] = table[0][1] = 1;;
  
  for (int i = 1; i <= s1.size(); )
  {
    if (s1[i] == s2[j]) {
      table[i][j] = table[i-1][j-1];
      ++i; ++j;
    }
    else {
      table[i][j] = table[i-1][j-1] // delete ++i
          table[i-1][j-1] // replace ++i, ++j
          table[i-1][j-1] // insert ++j
    }
  }
}


int main(int argc, char** argv)
{
  string s1("kitten");
  string s2("sitting");

  cout << EditDistanceRec(s1, s2, 0, 0) << endl;
  vector<vector<int> > dpTable(s1.size() + 1, vector<int>(s2.size() + 1, -1));
  cout << EditDistanceMemoized(s1, s2, 0, 0, dpTable) << endl;
  return 0;
}


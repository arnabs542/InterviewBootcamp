#include <iostream>
#include <string>
#include <cassert>
#include <vector>

using namespace std;


bool editDistance(const string& str1, const string& str2)
{
  int len1 = str1.length();
  int len2 = str2.length();

  if ((len1 != len2) && (abs(len1 - len2) != 1))
    return false;

  int i=0, j=0;

  vector<vector<int> > table(len1+1, vector<int>(len2+1, 0));

  table[0][1] = 1;
  table[1][0] = 1;

  for (int i = 0; i < len1; ++i)
  {
    for (int j = 0; j < len2; ++j)

    {
      if (str1[i] == str2[j])
        table[i+1][j+1] = table[i][j];

      table[i+1][j+1] = min(table[i][j+1] + 1,
                            table[i+1][j] + 1);
    }
  }

  return table[len1][len2];
}

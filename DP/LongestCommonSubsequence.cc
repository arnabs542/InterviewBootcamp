/*
Comments :
Given two sequences, find the longest subsequence present in both of them
Subsequences are not required to occupy consecutive positions in the sequences
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

string getString(vector<vector<int> >& dp, string& strX, string& strY, int n, int m)
{
    int i=0, j=0;
    string res;
    
    while (i < n && j < m)
    {
        if (strX[i] == strY[j])
        {
            res.push_back(strX[i]);
            ++i; ++j;
        }
        else
        {
            if (dp[i+1][j] > dp[i][j+1])
                ++i;
            else
                ++j;
        }
    }
    return res;
}

string getLCS_DP(string& strX, string& strY)
{
	vector<vector<int> > dp(strX.size()+1, vector<int>(strY.size()+1, 0));

	for (int i=0; i <= strX.size(); ++i)
		dp[i][strY.size()] = 0;
	for (int i=0; i <= strY.size(); ++i)
		dp[strX.size()][i] = 0;

	for (int i=strX.size()-1; i >=0; --i)
	{
		for (int j=strY.size()-1; j >= 0; --j)
		{
			if (strX[i] == strY[j])
				dp[i][j] = 1 + dp[i+1][j+1];
			else
				dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
		}
	}

	return getString(dp, strX, strY, strX.size(), strY.size());
}

#if 0
string getLCSRec(string strX, string strY, int i, int j, string res)
{
    if (i == strX.size() || j == strY.size())
        return res;
    
    if (strX[i] == strY[j]) {
        res.push_back(strX[i]);
        return getLCSRec(strX, strY, i+1, j+1, res);
    }
    
    string tmpStr = res;
    string res1 = getLCSRec(strX, strY, i+1, j, res);
    string res2 = getLCSRec(strX, strY, i, j+1, tmpStr);
    
    if (res1.size() > res2.size())
        return res1;
    return res2;
}
#endif

string getLCS(string strX, string strY) 
{
	//string res;
	//return getLCSRec(strX, strY, 0, 0, res);
	return getLCS_DP(strX, strY);
	int x = strX.size();
	int y = strY.size();
}

int main(int argc, char** argv)
{
  assert(getLCS("AGGTAB", "GXTXAYB") == "GTAB");
  assert(getLCS("ABCDGH", "AEDFHR") == "ADH");
  assert(getLCS("ABCDEFG", "BCDGK") == "BCDG");
  assert(getLCS("A", "B") == "");
  return 0;
}


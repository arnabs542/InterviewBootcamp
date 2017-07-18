/*
Comments :
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPalindrome(const string& str, int i, int j)
{
    while (i < j)
    {
        if (str[i++] != str[j--])
            return false;
    }
    return true;
}

void palindromicDecompositionRec(const string& str, int index, vector<string>& res)
{
    if (index >= str.length())
        return;
    
    res.push_back(str.substr(index,1));
    
    for (int i=0; i<index; ++i) {
        if (isPalindrome(str, i, index))
            res.push_back(str.substr(i, index - i +1));
    }
    palindromicDecompositionRec(str, index+1, res);
}

vector < string > palindromicDecomposition(string strInput) {

    vector<string> res;
    palindromicDecompositionRec(strInput, 0, res);
    return res;
}


int main(int argc, char** argv)
{
  string str("aba");
  vector<string> res = palindromicDecomposition(str);
  for (auto s : res)
    cout << s << endl;

  return 0;
}


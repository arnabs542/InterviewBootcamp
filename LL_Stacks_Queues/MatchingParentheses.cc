/*
Comments :
Find the length of the longest substring(contiguous) that has matching opening
and closing parantheses. We only need length not the substring itself. you may
assume valid input for the purpose of this exercise i.e input string only has
parentheses and nothing else

e.g.
Input "()()()", Output 6
Input "((((())(((()" Output 4
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int maxLenMatchingParen(const string& strParenExpression) {
  stack<char> st;
  int maxSoFar = 0;
  int currLen = 0;

  for (int i = strParenExpression.length()-1; i >=0; --i)
  {
    char ch = strParenExpression[i];

    switch (ch)
    {
      case ')':
        st.push(')');
        break;

      case '(':
        if (!st.empty()) {
          currLen += 2;
          st.pop();
        }
        else {
          maxSoFar = max(maxSoFar, currLen);
          currLen = 0;
        }
        break;
    }
  }

  return max(maxSoFar, currLen);
}

int main(int argc, char** argv)
{
  cout << maxLenMatchingParen("((((())(((()") << endl;
  return 0;
}


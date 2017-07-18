/*
Comments :
Given a string of integers as input, put between each pair of digits, one of
{"", "*", "+"}, such that the expression you get evaluated to K(a number also
given as input). Putting an empty string ("") between two numbers means, that
the numbers are joined to form a new number  (e.g. 1 ""  2  = 12)
Order of integers given in the input needs to remain the same.

Input:
1. String of positive integers
2. Target K (given constant)

Output:
All possible strings that evaluate to K

e.g. If the input string is "222" and target(K) is 24, two possible answers are:
1. 22 + 2
2. 2+22

Realize that the precedence of operatos matters
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cctype>

using namespace std;
vector<char> operators = {' ', '*', '+'};

int evaluateExpr(const string& str, int index)
{
  stack<int> operandS;
  stack<char> operatorS;
    
  int value = 0;
  
  for (int i = 0; i < index; ) {
      switch(str[i])
      {
          case '*':
              operatorS.push('*');
              ++i;
              break;
              
          case '+':
              while (!operatorS.empty() && operatorS.top() == '*') {
                  if (operandS.empty())
                    exit(1);
                  int a = operandS.top(); operandS.pop();
                  if (operandS.empty())
                    exit(1);
                  int b = operandS.top(); operandS.pop();
                  int c = a * b;
                  operandS.push(c);
                  operatorS.pop();
              }
              operatorS.push('+');
              ++i;
              break;
              
          case '0':
          case '1':
          case '2':
          case '3':
          case '4':
          case '5':
          case '6':
          case '7':
          case '8':
          case '9':
              int n = str[i++] - '0';
              while (i < index && isdigit(str[i])) {
                  n = n*10 + str[i++] - '0';
              }
              operandS.push(n);
              break;
      }
  }
    
  while (!operatorS.empty())
  {
      char ch = operatorS.top(); operatorS.pop();
      int a = operandS.top(); operandS.pop();
      int b = operandS.top(); operandS.pop();
      
      switch(ch) {
          case '+':
              operandS.push(a+b);
              break;
              
          case '*':
              operandS.push(a*b);
              break;
      }
      
  }
    
    return operandS.top();
}

string constructResultString(const string& str, int index, int K)
{
  return str.substr(0, index) + "=" + to_string(K);
}


// index points to the char in the input string to use in this recursive call
// r_index is the next empty position in the res string
void expressionCreatorRec(string& strDigits, 
                          int index, 
                          int iK, 
                          string& res, 
                          int r_index, 
                          vector<string>& resVec)
{
    if (index == strDigits.length()) {
        if (evaluateExpr(res, r_index) == iK)
            resVec.push_back(constructResultString(res, r_index, iK));
        return;
    }

    for (auto ch : operators) {
      int r = r_index;
        if (ch != ' ')
            res[r++] = ch;
        res[r++] = strDigits[index];
        expressionCreatorRec(strDigits, index+1, iK, res, r, resVec);
    }
    
}

#if 0
void expressionCreatorRec(string& strDigits,
                          int index,     // curr index into strDigits
                          int iK,        // sum we want to achieve
                          string& res,   // result string so far 
                          int r_index,   // curr index into res string
                          char  lastOp,  // last operator used to evaluate partialRes
                          int lastOperand, // last operand
                          int partialRes,// partial expression value
                          vector<string>& resVec)
{
  if (index == strDigits.length()) {
    if (partialRes == iK) {
      resVec.push_back(constructResultString(res, r_index, iK));
    }

    return;
  }
  
  for (auto op : operators) {
    
    int r = r_index;
    int updatedOperand = 0;
    int currDigit = strDigits[index] - '0';
    int pResult = partialRes;
    int lOperand = 0;
    char lOperator;

    switch (op) {
      case ' ':
        updatedOperand = lastOperand * 10 + currDigit;
        pResult = updatedOperand;
        switch (lastOp)
        {
          case '+':
            pResult -= lastOperand;
            pResult += updatedOperand;
            break;

          case '*':
            pResult /= lastOperand;
            pResult *= updatedOperand;
            break;

        }
        lOperator = lastOp; // remains the same
        lOperand = updatedOperand;
        break;

      case '*':
        if (lastOp == '+') {
          pResult -= lastOperand;
          pResult += (lastOperand * currDigit);
        } else {
          pResult = lastOperand * currDigit;
        }

        lOperator = '*';
        lOperand = currDigit;
        res[r++] = op;
        break;

      case '+':
        lOperator = '+';
        lOperand = currDigit;
        pResult += currDigit;
        res[r++] = op;
        break;
    
    }
    res[r++] = strDigits[index];
    expressionCreatorRec(strDigits, index+1, iK, res, r, lOperator, lOperand,
                         pResult, resVec);
  }
}
      
#endif 

vector < string > expressionCreator(string strDigits, int iK) {

    vector<string> resVec;
    string res(strDigits.length()*2, ' ');
    res[0] = strDigits[0];
    expressionCreatorRec(strDigits, 1, iK, res, 1, resVec);
    return resVec;
}


int main(int argc, char** argv)
{
  string str = "222";
  vector<string> res = expressionCreator(str, 24);

  for (auto s : res)
    cout << s << endl;

  return 0;
}


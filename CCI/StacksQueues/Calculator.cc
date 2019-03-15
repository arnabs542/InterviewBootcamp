#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <cassert>

using namespace std;

float getResult(float op1, float op2, char oper)
{
  float res;

  switch(oper)
  {
    case '+':
      res = op1 + op2;
      break;

    case '-':
      res = op1 - op2;
      break;

    case '*':
      res = op1 * op2;
      break;

    case '/':
      res = op1 / op2;
      break;
  }
  return res;
}

bool isDigit(char ch)
{
  return ch >= '0' && ch <= '9';
}

int precedence(char ch)
{
  int prec = 0;
  switch (ch)
  {
    case '+':
    case '-':
      prec = 1;
      break;

    case '*':
    case '/':
      prec = 2;
      break;
  }

  return prec;
}

float calculate(const string& expr)
{
  stringstream iss(expr);

  char ch;
  stack<float> s1;
  stack<char> s2;

  while (iss >> ch)
  {
    if (isDigit(ch))
    {
      iss.unget();
      int number;
      iss >> number;
      s1.push(number);
    }
    else
    {
      if (!s2.empty())
      {
        while (!s2.empty() && (precedence(ch) <= precedence(s2.top())))
        {
          char oper = s2.top(); s2.pop();
          assert (s1.size() >= 2);
          int op1 = s1.top(); s1.pop();
          int op2 = s1.top(); s1.pop();
          s1.push(getResult(op2, op1, oper));
        }
      }
      s2.push(ch);
    }
  }

  while (!s2.empty())
  {
    assert(s1.size() >= 2);
    float op1 = s1.top(); s1.pop();
    float op2 = s1.top(); s1.pop();
    s1.push(getResult(op2, op1, s2.top()));
    s2.pop();
  }

  cout << s1.size() << endl;
  return s1.top();
}


int main()
{
  cout << calculate("2+3/9*6+10") << endl;
  return 0;
}

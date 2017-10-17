/*
Comments :

Complexity : TimeComplexity(n * 2**n))
SpaceComplexity : O(n)
*/

#include <iostream>
#include <string>

using namespace std;

void printStr(const string& str, int index)
{
  for (int i=0; i < index; ++i)
    cout << str[i];
  cout << endl;
}

void printWellFormedRec(int N, int open, int closed, string& str, int index)
{
  if (closed > open)
    return;
  if (closed == N)
    printStr(str, index);

  if (open < N) {
    str[index] = '(';
    printWellFormedRec(N, open+1, closed, str, index+1);
  }
  if (closed < N) {
    str[index] = ')';
    printWellFormedRec(N, open, closed+1, str, index+1);
  }
}

void printWellFormed(int n)
{
  string str;
  for (int i = 1; i <= n; ++i)
    printWellFormedRec(n, 0, 0, str, 0);
}

int main(int argc, char** argv)
{
  printWellFormed(atoi(argv[1]));
  return 0;
}


/*
Comments :
*/

#include <iostream>
#include <string>

using namespace std;

static const char WILD_CHAR = '?';

void printWildCard(string& str, int index)
{
    if (index == str.length())
    {
        cout << str << endl;
        return;
    }
    
    if (str[index] == WILD_CHAR) 
    {
        str[index] = '0';
        printWildCard(str, index+1);
        str[index] = '1';
        printWildCard(str, index+1);
        str[index] = WILD_CHAR;
    }
    else
    {
        printWildCard(str, index+1);
    }
}

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  string inputStr="1?1";
  printWildCard(inputStr, 0);
  return 0;
}

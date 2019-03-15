#include <iostream>
#include <string>

#include <string>

using namespace std;


void paren(int count, int open, string& str)
{
  if (count == 0)
  {
    int open2 = open;
    cout << str ;
    while(open2--)
      cout << ')';
    cout << endl;
    return;
  }

  str += '(';
  paren(count-1, open+1, str);
  str.pop_back();

  if (open) {
    str += ')';
    paren(count, open-1, str);
    str.pop_back();
  }
}


int main(int argc, char** argv)
{
  string str;
  paren(stoi(argv[1]), 0, str);

  return 0;
}




/*
Comments :
Implement a regular expression matcher, supporting the following characters
- (.) - a dot matches any single character
- (*) - a start matches zero or more of the preceding element
E.g:
aab matches the RE c*a*b
aaaaaa matches the RE .a*
*/

#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>

using namespace std;

bool isMatch(string& strText, string& strPattern)
{
  enum State {START = 0, 
              STAR, 
              DOT, 
              END};

  State state = START;
  int i=0, j=0;

  reverse(strText.begin(), strText.end());
  reverse(strPattern.begin(), strPattern.end());

  cout << "text: " << strText << " " << "pattern: " << strPattern << endl;

  while (true)
  {
    switch (state)
    {
      case START:
        cout << i << " " << j << "start" << endl;
        while ((i < strText.size()) && (j < strPattern.size()) && (strText[i] == strPattern[j])) {
          ++i; ++j;
        }
        if (i == strText.size() || j == strPattern.size())
          state = END;
        else if (strPattern[j] == '*')
          state = STAR;
        else if (strPattern[j] == '.')
          state = DOT;
        else
          state = END;
        break;

      case STAR:
        cout << i << " " << j << "star" << endl;
        ++j;
        if (strPattern[j] == '.')
          strPattern[j] = strText[i];

        while ((i < strText.size()) && (strText[i] == strPattern[j])) {
          ++i;
        }
        j += 1;
        state = START;
        break;

      case DOT:
        cout << i << " " << j << "dot" << endl;
        ++i; ++j;
        state = START;
        break;

      case END:
        cout << i << " " << j << "end" << endl;
        if (j == strPattern.size())
          return true;

        if (i==strText.size()) {
          while (j < strPattern.size() && strPattern[j] == '*')
            j+=2;

          if (j == strPattern.size())
            return true;
        }
        
        return false;
        break;
    }
  }
  return false;
}

int main(int argc, char** argv)
{
  string text = "aa", pattern="a*";
  assert(isMatch(text, pattern) == true);
 
  text = "aa"; pattern="a";
  assert(isMatch(text, pattern) == true);
  
  text = "ab", pattern=".b";
  assert(isMatch(text, pattern) == true);

  text = "aa", pattern=".*";
  assert(isMatch(text, pattern) == true);

  text = "mississippi", pattern = "mis*is*p*.";
  assert(isMatch(text, pattern) == false);

  text="aab", pattern = "c*a*b";
  assert(isMatch(text, pattern) == true);

  text = "ab", pattern = ".*";
  assert(isMatch(text, pattern) == true);
  return 0;
}


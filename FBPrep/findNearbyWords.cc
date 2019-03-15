/*
Comments :
When you type on a touch screen, ocassionally the wrong word is registered.
For example:
When typing "Hello" a "G" may be registered instead of "H"
Write a function that given a string, returns all nearby words

You are given the following helper functions

// for a given char return all nearby chars
(a) function get_nearby_chars(string $character):Set<string>

// for a given string, return true if it is a word
(b) function is_word(string $word): bool

Implement this:

// for a given word, get all possible nearby words
function nearby_words(string word):Set<string>

*/

#include <iostream>
#include <string>
#include <set>


using namespace std;

set<char> get_nearby_chars(char ch)
{
}

bool is_word
{
}

void get_nearby_words(string& word, int index, set<string>& res, string&
                             pString)
{
  if (index == word.size()) 
  {
    res.insert(pString);
    return;
  }

  for (auto ch : get_nearby_chars(word[index]))
  {
    pString[index] = ch;
    get_nearby_words(word, index+1, res, pString);
  }
}

set<string> nearby_words(string& word)
{
  set<string> res;
  string pString(word.size(), '');
  get_nearby_words(word, 0, res, pString);
  for (auto w: res)
  {
    if (!is_word(w))
      res.erase(w);
  }
  return res;
}

int main(int argc, char** argv)
{
  return 0;
}


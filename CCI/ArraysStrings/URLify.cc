#include <vector>
#include <iostream>
#include <string>
#include <stdexcept>

using std::vector;
using std::cout;
using std::endl;
using std::string;


void urlify(string& word, int len)
{
  int totalLen = word.size()-1;

  int i = len-1;
  int j = totalLen;

  while (i >= 0)
  {
    if (word[i] == ' ') {
      if (j < 2)
        throw std::runtime_error("Invalid input");

      word[j] = '0';
      word[--j] = '2';
      word[--j] = '%';
      --j;
      --i;
    } else {
      word[j--] = word[i--];
    }
  }
}


int main()
{
  string str = "Mr John Smith    ";
  urlify(str, 13);

  for (auto ch : str)
    cout << ch ;
  cout << endl;

  return 0;
}

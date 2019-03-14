/*
Comments :
*/

#include <iostream>
#include <string>

using namespace std;

string RLE(string strinput) {
	string res=""; 

	for (int index = 0; index < strinput.size();)
	{
		int count = 1;
    char c = strinput[index];
    index++;
		while (index < strinput.size() && strinput[index] == c) 
    {
      ++index;
      ++count;
    }
		if (count >  1)
			res += to_string(count);
    res.push_back(c);
	}

	return res;
}


int main(int argc, char** argv)
{
  cout << RLE("a12bbb") << endl;
  return 0;
}


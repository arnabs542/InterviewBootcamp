/*
Comments :
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <locale>

using namespace std;

string shortestCompletingWord(string licensePlate, vector<string>& words) {
	unordered_map<char, int> letters;

	for (auto c : licensePlate)
	{
		if (isalpha(c))
		{
			char ch = tolower(c);
			if (letters.find(ch) == letters.end())
				letters[ch] = 1;
			else
				letters[ch]++;
		}
	}

  auto sortRule = [] (const string& s1, const string& s2) -> bool
  {
    return s1.length() < s2.length();
  };

	stable_sort(words.begin(), words.end(),sortRule);

	for (auto const& word : words)
	{
		unordered_map<char, int> copy = letters;

		for (auto const ch : word)
		{
			auto it = copy.find(ch);
			if (it != copy.end())
			{
				it->second--;
				if (it->second == 0) {
					copy.erase(it);
					if (copy.empty())
						return word;
				}
			}           
		}
	}

  return "";
}

int main(int argc, char** argv)
{
  vector<string> words = {"step","steps","stripe","stepple"};
  cout << shortestCompletingWord("1s3 PSt", words)
      << endl;
  return 0;
}


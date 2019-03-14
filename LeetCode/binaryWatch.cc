/*
Comments :
A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6
LEDs on the bottom represent the minutes (0-59).

Each LED represents a zero or one, with the least significant bit on the right.
Given a non-negative integer n which represents the number of LEDs that are
currently on, return all possible times the watch could represent.

Example:

Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16",
"0:32"]
Note:
The order of output does not matter.
The hour must not contain a leading zero, for example "01:00" is not valid, it
should be "1:00".
The minute must be consist of t
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <cstdlib>

using namespace std;

unordered_map<int, vector<int> > bits_to_values;

vector<string> readBinaryWatch(int num)
{
  vector<string> res;

  for (int hourBits=0; hourBits <= 3 && hourBits <= num; ++hourBits)
  {
    for (int minuteBits=0; minuteBits <= 6 && minuteBits <= num; ++minuteBits)
    {
      int total = hourBits + minuteBits;
      if (total != num) continue;
      for (auto hour : bits_to_values[hourBits])
      {
        if (hour > 11)
          continue;
        for (auto minute: bits_to_values[minuteBits])
        {
          if (minute > 59) continue;
          if (minute < 10)
            res.push_back(to_string(hour) + ":0" + to_string(minute));
          else
            res.push_back(to_string(hour) + ":" + to_string(minute));
        }
      }
    }
  }

  return res;
}

int get_bits_set(int num)
{
  int bits = 0;

  while (num)
  {
    if (num & 0x1)
      ++bits;
    num >>= 1;
  }
  return bits;
}

int main(int argc, char** argv)
{

  for (int i=0; i <= 59; ++i)
  {
    int bits = get_bits_set(i);
    bits_to_values[bits].push_back(i);
  }

  for (auto r: readBinaryWatch(atoi(argv[1])))
    cout << r << " ";
  cout << endl;

  return 0;
}


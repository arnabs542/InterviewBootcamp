/*
Comments :
Given a phone keypad as shown below

1 2 3
4 5 6 
7 8 9
  0

How many different 10 digit numbers can be formed starting from 1.
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<int, vector<int> > nextDigits = {{1,{6,8}}, {2, {7,9}}, {3, {4,8}}, 
                                     {4,{0,3,9}}, {5,{}},     {6, {0,1,7}}, 
                                     {7,{6,2}}, {8, {1,3}}, {9, {4,2}}, 
                                     {0,{4,6}}
                                       };

long numPhoneNumbersDP(int startdigit, int phonenumberlength)
{
  vector<vector<long> > table(10, vector<long>(phonenumberlength+1, 0));

  for (int i = 0; i <= 9; ++i)
  {
    table[i][0] = 0;
    table[i][1] = 1;
  }

  for (int len=2; len <= phonenumberlength; ++len)
  {
    for (int digit=0; digit <= 9; ++digit)
    {
      for (auto nextdigit : nextDigits[digit])
        table[digit][len] += table[nextdigit][len-1];
    }
  }
  return table[startdigit][phonenumberlength];
}

long numPhoneNumbers(int startdigit, int phonenumberlength)
{
  if (phonenumberlength == 1)
    return 1;

  long count = 0;
  for (auto digit : nextDigits[startdigit])
    count += numPhoneNumbers(digit, phonenumberlength-1);

  return count;
}

int main(int argc, char** argv)
{
  cout << numPhoneNumbers(1,10) << "  " << numPhoneNumbersDP(1, 10) << endl;
  return 0;
}


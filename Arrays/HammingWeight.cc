/*
Comments :
*/

#include <iostream>
#include <cmath>
#include <unordered_map>
#include <vector>

using namespace std;

int countBits(int num)
{
  static const uint8_t m1 = 0x55;
  static const uint8_t m2 = 0x33;
  static const uint8_t m3 = 0x0F;

  int b0 = (num >> 0) & m1;
  int b1 = (num >> 1) & m1;

  int c = b0+b1;

  int d0 = (c>>0) & m2;
  int d1 = (c>>2) & m2;

  int e = d0 + d1;

  int f0 = (e>>0) & m3;
  int f1 = (e>>4) & m3;
  return f0+f1;
}

int printCountOfBitSet(vector<int>& intArr)
{
  unordered_map<int, int> table;
  for (int i = 0; i <= pow(2,8)-1; ++i)
    table[i] = countBits(i);

  int count = 0;
  for (auto const n : intArr)
  {
    int a = n & 0xFF;
    int b = (n >> 8 ) & 0xFF;
    int c = (n >> 16) & 0xFF;
    int d = (n >> 24) & 0xFF;
 
    cout << n << " " << a << " " << b << " " << c << " " << d << endl; 
    cout << table[a] << " " << table[b] << " " << table[c] << " " << table[d] << endl; 
    count += (table[a] + table[b] + table[c] + table[d]);
  }

  return count;
}

int main(int argc, char** argv)
{
  vector<int> array = {29};
  cout  << printCountOfBitSet(array) << endl;
  return 0;
}


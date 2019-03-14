/*
Comments :
Given an input file with 4 billion integers, provide an algorithm to generate an
integer that is not contained in the file. Assume you have 1 GiB memory. Follow
up with what you would do if you have only 10 MiB of memory.
*/

#include <iostream>

using namespace std;

static const double oneGB = (2 << 30) / (sizeof(int));
unsigned int table[oneGB] = {0};

void set(long long val)
{
  int index = val/(sizeof(int)*8);
  int bitPos = val%(sizeof(int)*8);
  int mask = 1 << bitPos;
  table[index] |= mask;
}

int missing(int val)
{
  int i = 1;
  while(val && !val & 0x1)
  {
    val >>= 1;
    ++i;
  }
  return i;
}

long long findMissing()
{
  int allOnes = (2 << sizeof(int)) - 1;
  for (long long i = 0; i < oneGB; ++i)
  {
    if (table[i] & allOnes != allOnes)
    {
      return (sizeof(int) * 8) + missing(~table[i]);
    }
  }
  return 0;
}


int main(int argc, char** argv)
{
  cout << oneGB << endl;
  return 0;
}


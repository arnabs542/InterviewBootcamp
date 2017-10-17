/*
Comments :
Given an input file with 4 billion integers, write an algorithm to find an
integer absent in the filr absent in the file. Assume you have 1GB memory

Case I : 4 billion integers, 1GB memory
=====================================
Assuming each integer is 4 bytes long
Input size = 4 * 2 ^ 30 * 4 * 2^ 3 = 2 ^ 37 bits
Memory size= 2^30 * 2 ^3 = 2 ^ 33 bits

So : Input = 16 * Memory
So it is not possible to represent each input integer as a int in memory. But we
could represent each int as a bit in memory, for this we would need = 2 ^ 32
bits = 2 ^ 29 bytes < 1GB


Case II : 4 billion ints, 10 MB memory
======================================
Input size = 16 * 2 ^ 10 MB
Memory    =  10 MB
so Input/Memory = 1.6 KB
*/

#include <iostream>
#include <vector>
#include <cassert>
#include <fstream>

using namespace std;

#define SIZE 134217728  // 2 ^ 27

vector<int> buffer(SIZE, 0);

void setInt(int val)
{
  int indexInBuffer = val/8;
  int bitPos = val % 8;


  assert(indexInBuffer < SIZE);
  buffer[indexInBuffer] |= (1 << bitPos);
}

bool isSet(int val)
{
  int indexInBuffer = val/8;
  int bitPos = val % 8;

  assert(indexInBuffer < SIZE);

  return (buffer[indexInBuffer] & (0x1 << bitPos)) != 0;
}

void readFile()
{
  ifstream ifs("input.txt",fstream::in);
  int num;

  while (ifs >> num)
    setInt(num);
}

void findMissing()
{
  cout << "Missing number are: " << endl;

  for (int i = 0; i <= numeric_limits<int>::max(); ++i)
    if (!isSet(i))
      cout << i << " ";
  cout << endl;
}

int main(int argc, char** argv)
{
  readFile();
  findMissing();
  return 0;
}


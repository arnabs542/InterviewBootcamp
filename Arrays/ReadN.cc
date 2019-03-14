/*
Comments :
*/

#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

static const K = 5;
static queue<char> buffer;

int readK(char* output)
{
  return K;
}

int readN(char[] output, int N)
{
  int index = 0;
  if (!buffer.empty() && index < N) {
    output[index++] = q.front();
    q.pop();
  }

  int remainingChar = N - index;
  if (!remainingChar) 
    return N;


  char array[K];
  int readChars;

  while (remainingChar >= K)
  {
    int readChars = readK(array);
    memcpy(&output[index], array, readChars);

    if (readChars != K)
      return index + readChars;

    remainingChar -= K;
    index += K;
  }

  if (!remainingChar)
    return index;

  readChars = readK(array);

  if (readChars > remainingChar) {
    memcpy(&output[index], array, remainingChar);
  }
  else {
    memcpy(&output[index], array, readChars);
  }


  int i = remainingChar;
  for (auto c = array[i]; i < readChars; ++i)
    q.push(c);

  return N;

}

int main(int argc, char** argv)
{
  return 0;
}


/*
Comments :
Design a rate limiter for concurrent API requests that can be used for
throttling API requests from any given API client based on configured quotas and
security policy.
https://stackoverflow.com/questions/667508/whats-a-good-rate-limiting-algorithm
*/

#include <iostream>
#include <chrono>

using namespace std;

void printMessage()
{
  int rate = 1; // one message
  int per = 1; // time in seconds
  static int allowance = rate;
  static auto last_check = chrono::system_clock::now();

  while (allowance < 1)
  {
    auto current_time = chrono::system_clock::now();
    auto time_lapse = chrono::duration_cast<chrono::seconds>(current_time -
                                                             last_check);

    allowance += rate/per * time_lapse.count();
    if (allowance > rate)
      allowance = rate;
  }

  auto time_lapse = chrono::duration_cast<chrono::seconds>(chrono::system_clock::now() - last_check);
  last_check = chrono::system_clock::now();

  if (allowance >= 1) {
    allowance -= 1;
    cout << time_lapse.count() << " hello there" << endl;
  }


}

int main(int argc, char** argv)
{
  for (int i = 1; i <= 10; ++i)
    printMessage();

  return 0;
}


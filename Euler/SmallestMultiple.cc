/* Find the smallest positive number that is evenly divisible by all of the
 * nu,bers from 1 to 20
 */
#include <cmath>
#include <map>
#include <iostream>
#include <cfenv>


using namespace std;

void findAllPrimes(int* table, int num)
{
  for (int i=2; i <= sqrt(num); ++i)
  {
    int multiple = i;
    int n = multiple * 2;
    while (n <= num) {
      table[n] = 1;
      n += i;
    }
  }
}

int findSmallest()
{
  int table[21] = {};
  
  findAllPrimes(table, 20);

  map<int, int> factors;

  for (int i = 2; i <= 20; ++i)
    if (!table[i])
      factors[i] = 1;

  int res = 1;
  for (auto fv: factors)
  {
    int count = log(20)/log(fv.first);
    cout << "for: " << fv.first << "count: " << count << endl;
    factors[fv.first] = count;
    res *= pow(fv.first, count);
  }

  return res*2;
}

int main()
{
  cout << findSmallest() << endl;
  return 0;
}

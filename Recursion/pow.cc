/*
Comments :
*/

#include <iostream>
#include <iomanip>

using namespace std;

double powRec(double dblbase, int ipower) {

  if (ipower == 1)
    return dblbase;
  if (ipower == 0)
    return 1;

  double val = powRec(dblbase, ipower/2);

  if (ipower % 2)
    return val*val*dblbase;
  return val*val;
}

double pow(double dblbase, int ipower) {
  if (ipower < 0) {
    double base = 1.0/dblbase;
    return powRec(base, ipower);
  } 
  return powRec(dblbase, ipower);
}

int main(int argc, char** argv)
{
  cout << "10.0, 3 " <<  std::fixed << std::setprecision(5) << pow(10.0, 3) << " " << endl;
  cout << "4.5, -3 " <<  pow(4.5, -3) << " " << endl;
  cout << "4.0, 0 "  <<  pow(4.0, 0)  << " " << endl;
  return 0;
}


#include <stdio.h>
#include <iostream>
#include <cmath>
#include <boost/multiprecision/mpfr.hpp>
#include <boost/multiprecision/gmp.hpp> 
using namespace boost::multiprecision;
using namespace std;
int main()
{
  long long int n = 1000000;
  cout.precision(n+2);
  mpfr_float::default_precision(n);
  mpfr_float a_old=0;
  mpfr_float a = 1.5;
  int i = 0;
  while(a!=a_old){
    a_old=a;
    a=(2/a+a)/2;
    i++;
    cout << i << "\n";
  }
  // std::cout << a << std::endl;
  return 0;
   
}

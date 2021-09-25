#include <stdio.h>
#include <fstream>
#include <iostream>
#include <cmath>
#include <future>
#include <boost/multiprecision/mpfr.hpp>
#include <boost/multiprecision/gmp.hpp> 
using namespace boost::multiprecision;
using namespace std;

mpz_int calc_num(mpz_int a, mpz_int b) {
  return a*a+2*b*b;
}

mpz_int calc_dem(mpz_int a, mpz_int b) {
  return 2*a*b;
}

int main()
{
  fstream num, dem;
  num.open("num.txt",ios::out);
  dem.open("dem.txt",ios::out);
  mpz_int a = 3;
  mpz_int b = 2;
  mpz_int a_temp;
  for(int i=0;i<35;i++ ){
    a_temp = a;
    future<mpz_int> futnum =  async(calc_num, a,b);
    future<mpz_int> futdem =  async(calc_dem,a_temp,b);
    a = futnum.get();
    b = futdem.get();
    cout << i << "\n";
  }
  num << a << std::endl;
  dem << b << std::endl;
  num.close();
  dem.close();
  return 0;
   
}

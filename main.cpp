#include <stdio.h>
#include <fstream>
#include <iostream>
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
mpz_int simplify(mpz_int a, mpz_int x){
  return a/x;


}
int main()
{
  fstream num, dem, num_prev, dem_prev;
  mpz_int a = 3;
  mpz_int b = 2;
  mpz_int x;
  int n = 40;
  for(int i=0;i<=n;i++ ){
    future<mpz_int> futnum =  async(calc_num, a,b);
    future<mpz_int> futdem =  async(calc_dem,a,b);
    a = futnum.get();
    b = futdem.get();
    cout << i << "\n";
    if(i == n-1){
        num_prev.open("num_prev.txt",ios::out);
	num_prev << a;
	num_prev.close();
	dem_prev.open("dem_prev.txt",ios::out);
	dem_prev << b;
	dem_prev.close();
    }
  }
  num.open("num.txt",ios::out);
  num << a;
  num.close();
  dem.open("dem.txt",ios::out);
  dem << b;
  dem.close();
  return 0;
   
}

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <cstring>
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
  FILE *num, *dem, *num_prev, *dem_prev;
  mpz_int a = 3;
  mpz_int b = 2;
  mpz_int a_temp;
  mpz_int x;
  int n = 36;
  for(int i=0;i<n;i++ ){
    a_temp = a;
    a = a*a+2*b*b;
    b *= 2*a_temp;
    cout << i <<"\n";
    if(i == n-2){
      num_prev =fopen ("num_prev.bin","wb");
      mpz_out_raw(num_prev,a.backend().data());
      fclose(num_prev);
      dem_prev = fopen("dem_prev.bin", "wb");
      mpz_out_raw(dem_prev,b.backend().data());
      fclose(dem_prev);
    }
  }
  num =fopen ("num.bin","wb");
  mpz_out_raw(num,a.backend().data());
  fclose(num);
  dem = fopen("dem.bin", "wb");
  mpz_out_raw(dem,b.backend().data());
  fclose(dem);
  cout << "Written numerator\n";
  return 0;
   
}

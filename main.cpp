#include <stdio.h>
#include <fstream>
#include <iostream>
#include <cstring>
#include <future>
#include <boost/multiprecision/mpfr.hpp>
#include <boost/multiprecision/gmp.hpp>
using namespace boost::multiprecision;
using namespace std;

int main()
{
  FILE *num, *dem, *num_prev, *dem_prev;
  mpz_int a = 3;
  mpz_int b = 2;
  mpz_int c,d;
  mpz_int a_temp;
  mpz_int e;
  mpz_int x;
  int n = 36;
  for(int i=0;i<n;i++ ){
    a_temp = a;
    a = a*a+2*b*b;
    b *= 2*a_temp;
    cout << i <<"\n";
    if(i == n-2){
      d = b;
      c = a;
      
    }
  }
  e = a*d-b*c;
  long long int g = mpz_sizeinbase(b.backend().data(),10)+mpz_sizeinbase(d.backend().data(),10)-mpz_sizeinbase(e.backend().data(),10);
  cout <<"Guarrantied precision: " << g << "\n";
  fstream output;
  output.precision(0);
  output.open("output.txt",ios::out);
  mpz_int f=10;
  mpz_int h;
  mpz_pow_ui(&h.backend().data()[0],&f.backend().data()[0],g);
  output << (c*h)/d;
  output.close();
  return 0;
   
}

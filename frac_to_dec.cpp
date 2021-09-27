#include <stdio.h>
#include <boost/rational.hpp>
#include <fstream>
#include <iostream>
#include <cstring>
#include <future>
#include <cmath>
#include <boost/multiprecision/mpfr.hpp>
#include <boost/multiprecision/gmp.hpp>
using namespace boost::multiprecision;
using namespace std;

int main(){
  FILE *num, *dem, *num_prev, *dem_prev;
  mpz_int a,b,c,d,e;
  num = fopen("num.bin", "rb");
  mpz_inp_raw(&a.backend().data()[0], num);
  fclose(num);
  cout <<"Numerator read sucefully!\n";
  
  dem = fopen("dem.bin", "rb");
  mpz_inp_raw(&b.backend().data()[0], num);
  fclose(dem);
  cout <<"Demoinator read sucefully!\n";
  
  num = fopen("num_prev.bin", "rb");
  mpz_inp_raw(&c.backend().data()[0], num);
  fclose(num);
  cout <<"Previous numerator read sucefully!\n";
  
  dem = fopen("dem_prev.bin", "rb");
  mpz_inp_raw(&d.backend().data()[0], num);
  fclose(dem);
  cout <<"Previous demoinator read sucefully!\n";
  e = a*d-b*c;
  long long int g = mpz_sizeinbase(b.backend().data(),10)+mpz_sizeinbase(d.backend().data(),10)-mpz_sizeinbase(e.backend().data(),10);
  cout <<"Guarrantied precision: " << g << "\n";
  fstream output;
  output.precision(0);
  output.open("output.txt",ios::out);
  for(int i=0;i<g;i++){
    int h = 0;
    while(a>b){
      a-=b;
      h++;
    }
    output<< h;
    a*=10;
  }
  output.close();
  return 0;
}

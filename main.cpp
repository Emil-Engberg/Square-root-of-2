#include <stdio.h>
#include <gmp.h>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
  mpz_t a, b, a_temp, b_temp,x,b2,a2;
  mpz_init_set_ui(a,3);
  mpz_init_set_ui(x,3);
  mpz_init_set_ui(b,2);
  mpz_init_set_ui(b2,0);
  mpz_init_set_ui(a2,0);
  mpz_init_set_ui(a_temp,3);
  mpz_init_set_ui(b_temp,2);
  for(int i=0; i < 10;i++){
    mpz_set(a_temp,a);
    mpz_set(b_temp,b);
    mpz_mul_ui(a,a,4);
    mpz_mul(a,a,b);
    mpz_pow_ui(a2,a_temp,2);
    mpz_pow_ui(b2,b,2);
    mpz_mul_ui(b2,b2,2);
    mpz_add(b,a2,b2);
    mpz_gcd(x,a,b);
    mpz_divexact(a,a,x);
    mpz_divexact(b,b,x);
    cout << a << " " << b << "\n";
  }
  return 0;
   
}

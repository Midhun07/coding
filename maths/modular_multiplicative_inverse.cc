#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;

// To compute x^y under modulo m 
int power(int x, unsigned int y, unsigned int m) 
{ 
  if (y == 0) 
    return 1; 
  int p = power(x, y/2, m) % m; 
  p = (p * p) % m; 

  return (y%2 == 0)? p : (x * p) % m; 
}

long long fact(int num) {
  long long fac = 1;
  for (int i = 2; i <= num; i++) {
    fac = (fac * i) % mod;
  }
  return fac;
}

int main() {
  int a = 30;
  cout  << sizeof(long long) << " " << sizeof(unsigned int) << endl;
  cout << fact(a) << endl;
  cout << power(fact(a), mod - 2, mod) << endl;
  return 0;
}

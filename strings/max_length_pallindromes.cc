#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;

int power(int x, unsigned int y, unsigned int m) {
  if (y == 0)
    return 1;
  int p = power(x, y/2, m) % m;
  p = (p * p) % m;

  return (y%2 == 0)? p : (x * p) % m;
}

long long fact(long long num) {
  long long fac = 1;
  for (int i = 2; i <= num; i++) {
    fac = (fac * i) % mod;
  }
  return fac;
}

int main() {
  string s;
  cin >> s;
  int q = 0;
  cin >> q;
  while (q--) {
    int l = 0, r = 0, mid = 0;
    long long num = 0, den = 1, fr = 0;
    // const unsigned int len = l - r + 1;
    int a[256] = {0};
    cin >> l >> r;
    string sub = s.substr(l-1, r-l+1);
    cout << sub << endl;
    for (int i = 0; i < sub.length(); i++)
      a[sub[i]]++;

    for (int i = 0; i < 256; i++) {
      if (a[i]%2 == 0) {
        fr = a[i]/2;
      } else {
        fr = (a[i] - 1)/2;
        mid++;
      }
      num += fr;
      den *= power(fact(fr), mod-2, mod);
    }
    if (mid)
      cout << (fact(num) * den * mid) % mod << endl;
    else
      cout << (fact(num) * den) % mod << endl;
  }
  return 0;
}

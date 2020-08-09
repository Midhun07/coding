#include <bits/stdc++.h>
using namespace std;
uint64_t a[255][55] = {0};
int c[51] = {0};

uint64_t dp(int i, int k, int n) {
  if (i < 0 || k >= n)
    return 0;
  if (!i)
    return 1;
  if (a[i][k])
    return a[i][k];
  return a[i][k] = dp(i, k+1, n) + dp(i - c[k], k, n);
}

int main() {
  int m = 0, n = 0;
  cin >> m >> n;
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  dp(m, 0, n);
  cout << a[m][0] << endl;
  return 0;
}
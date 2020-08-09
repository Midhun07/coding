#include <bits/stdc++.h>
using namespace std;
#define INF 100000
int a[401][401];
int main() {
  int n = 0 , m = 0;
  cin >> n >> m;
  for (int i = 0; i < 401; i++) {
    for (int j = 0; j < 401; j++) {
      if (i == j) a[i][j] = 0;
      else a[i][j] = INF;
    }
  }
  while (m--) {
    int x = 0, y = 0, r = 0;
    cin >> x >> y >> r;
    a[x][y] = r;
  }
  for (int  k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
      }
    }
  }
  int q = 0;
  cin >> q;
  while (q--) {
    int l = 0, k = 0;
    cin >> l >> k;
    if (a[l][k] == INF)
      cout << -1 << endl;
    else
      cout << a[l][k] << endl;
  }
  return 0;
}
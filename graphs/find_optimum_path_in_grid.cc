#include <iostream>
using namespace std;

typedef map<pair<int, int>, pair<in, int>> mp;
int a[21][21];
int bad_cell = 0, good_cell  = 0;
void find_probability(int i, int j, int n, int m) {
  if (i > 20 || j > 20) {
    return;
  } else if (a[i][j] == '*') {
    bad_cell++;
    return;
  } else if (a[i][j] == '%') {
    good_cell++;
    return;
  } else if (a[i][j]) {

  }
}

int main() {
  int n = 0, m = 0, k = 0;
  int i = 0, j = 0, k = 0, l = 0;
  int s1 = 0, s2 = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'A') {
        s1 = i;
        s2 = j;
      }
    }
  }
  while (k--) {
    cin >> i >> j << k << l;
    mp[make_pair(i, j)] = make_pair(k, l);
  }
  bad_cell = 0; good_cell = 0;
  find_probability(s1, s2, n, m);
  return 0;
}

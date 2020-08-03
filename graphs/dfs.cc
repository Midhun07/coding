#include <bits/stdc++.h>
using namespace std;

int a[100][100];

void dfs(int n, int i, bool *vis) {
  if (vis[i])
    return;
  vis[i] = true;
  cout << i << " ";
  for (int k = 0; k < n; k++) {
    if (a[i][k]) {
      dfs(n, k, vis);
    }
  }
}

int main() {
  int m = 0, n = 0;
  cin >> m >> n;
  bool vis[m] = {false};
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < m; i++) {
    cout << "Path : ";
    dfs(n, i, vis);
    cout << endl;
  }
  return 0;
}

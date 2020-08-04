// Removing number of nodes so that resulting tree is
// a forest of trees with each tree having even number
// of nodes

#include <bits/stdc++.h>
using namespace std;
map<int, vector<int>> mp;
vector<int> vis;
int cnt = 0;

int dfs(int i) {
  if (vis[i])
    return 0;
  vis[i] = 1;
  if (mp[i].size() == 1)
    return 1;
  int total = 0;
  for (auto e : mp[i]) {
    if (!vis[e]) {
      int ans = dfs(e);
      if (ans % 2 == 0)
        cnt++;
      total += ans;
    }
  }
  return 1 + total;
}

int main() {
  int m = 0, n = 0;
  cin >> m >> n;
  for (int i = 0; i < n; i++) {
    int l = 0, k = 0;
    cin >> l >> k;
    mp[l].push_back(k);
    mp[k].push_back(l);
  }
  vis.assign(m+1, 0);
  dfs(1);
  cout << cnt << endl;
}
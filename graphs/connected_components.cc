#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> mp;

void dfs(int i, bool *vis) {
  if (vis[i])
    return;
  vis[i] = true;
  if (mp.find(i) != mp.end()) {
    auto j = mp[i].begin();
    while (j != mp[i].end()) {
      if (!vis[*j])
        dfs(*j, vis);
      j++;
    }
  }
}

int main() {
  freopen("in_cc_dfs.txt","r",stdin);
  int q = 0;
  cin >> q;
  while (q--) {
    mp.clear();
    int n = 0, m = 0, cl = 0, cr = 0;
    long long ans = 0;
    bool vis[100000] = {false};
    cin >> n >> m >> cl >> cr;
    long long rds = 0, libs = 0;
    for (int i = 0; i < m; i++) {
      int k = 0, l = 0;
      cin >> k >> l;
      mp[k].push_back(l);
      mp[l].push_back(k);
    }
    if (cl < cr || !m) {
      ans = n;
      ans *= cl;
      cout << ans << endl;
      continue;
    }
    for (int i = 1; i <= n; i++) {
      if (!vis[i]) {
        dfs(i, vis);
        libs++;
      }
    }
    rds = n - libs;
    // cout << n << " " << libs << " " << rds << endl;
    libs *= cl;
    rds *= cr;
    ans = libs + rds;
    cout << ans << endl;
  }
  return 0;
}

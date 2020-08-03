#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> mp;
int mem_cnt = 0;

void dfs(int i, bool *vis) {
  if (vis[i])
    return;
  vis[i] = true;
  mem_cnt++;
  if (mp.find(i) != mp.end()) {
    auto j = mp[i].begin();
    while (j != mp[i].end()) {
      if (!vis[*j]) {
          dfs(*j, vis);
      }
      j++;
    }
  }
}

int main () {
    int n = 0, p = 0;
    cin >> n >> p;
    mp.clear();
    bool vis[100000] = {false};
    long long ans = 0;
    vector<int> gp;
    while (p--) {
        int k = 0, l = 0;
        cin >> k >> l;
        mp[k].push_back(l);
        mp[l].push_back(k);
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, vis);
            if (mem_cnt)
                gp.push_back(mem_cnt);
        }
        mem_cnt = 0;
    }
    long long sum_sq = 0;
    long long ind_sq = 0;
    for (int i = 0; i < gp.size(); i++) {
        sum_sq += gp[i];
        ind_sq += gp[i] * gp[i];
    }
    ans = (pow(sum_sq, 2) - ind_sq) / 2;
    cout << ans << endl;
    return 0;
}
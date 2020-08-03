#include <bits/stdc++.h>
using namespace std;

priority_queue<pair<int, int>> pi;
map<int, vector<pair<int, int>>> mp;
vector<int> vi;
void process(int i) {
  vi[i] = 1;
  for (auto e : mp[i]) {
    if (!vi[e.first])
      pi.push(make_pair(-e.second, -e.first));
  }
}
int main() {
  int n = 0, m = 0;
  cin >> n >> m;
  while (m--) {
    int u = 0, v = 0, w = 0;
    cin >> u >> v >> w;
    mp[u].push_back(make_pair(v, w));
    mp[v].push_back(make_pair(u, w));
  }
  int s = 0;
  cin >> s;
  vi.assign(n, 0);
  process(s);
  int mst_cost = 0;
  while (!pi.empty()) {
    pair<int, int> q = pi.top(); pi.pop();
    if (!vi[-q.second]) {
      mst_cost += -q.first;
      process(-q.second);
    }
  }
  cout << mst_cost << endl;
  return 0;
}
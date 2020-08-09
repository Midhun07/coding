#include <bits/stdc++.h>
using namespace std;
#define INF 100000000
priority_queue<pair<long, int>> pi;
vector<long> dist;
map<int, vector<pair<int, long>>> mp;

int main() {
  int m = 0, n  = 0;
  freopen("in_dijkstra_reverse.txt", "r", stdin);
  cin >> m >> n;
  while (n--) {
    int l = 0, k = 0, j = 0;
    cin >> l >> k >> j;
    mp[l].push_back(make_pair(k, j));
    mp[k].push_back(make_pair(l, j));
  }
  dist.assign(m + 1, INF);
  dist[1] = 0;
  pi.push(make_pair(0, 1));
  while (!pi.empty()) {
    pair<int, int> p = pi.top(); pi.pop();
    int u = p.second; long w = -p.first;
    if (w > dist[u]) continue;
    for (auto e : mp[u]) {
      if (max(dist[u], e.second) < dist[e.first]) {
        dist[e.first] = max(dist[u], e.second);
        if (e.first != m)
          pi.push(make_pair(-dist[e.first], e.first));
      }
    }
  }
  if (dist[m] == INF) cout << "NO PATH EXISTS" << endl;
  else cout << dist[m] << endl;
  return 0;
}
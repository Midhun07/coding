#include <bits/stdc++.h>
using namespace std;
#define INF 100000
priority_queue<pair<int, int>> pq;
map<int, vector<pair<int, int>>> mp;
vector<int> dist;

int main() {
  freopen("in_dijkstra.txt", "r", stdin);
  int n = 0, m = 0, t = 0;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    mp.clear();
    while (m--) {
      int u = 0, v = 0, w = 0;
      cin >> u >> v >> w;
      mp[u].push_back(make_pair(v, w));
      mp[v].push_back(make_pair(u, w));
    }
    int s = 0;
    cin >> s;
    dist.assign(n + 1, INF);
    dist[s] = 0;
    pq.push(make_pair(0, s));
    while (!pq.empty()) {
      pair<int, int> p = pq.top(); pq.pop();
      int u = p.second, w = p.first;
      if (w > dist[u]) continue;
      for (auto e : mp[u]) {
        if (dist[u] + e.second < dist[e.first]) {
          dist[e.first] = dist[u] + e.second;
          pq.push(make_pair(dist[e.first], e.first));
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      if (i == s)
        continue;
      else if (dist[i] = INF)
        cout << -1 << " ";
      else
        cout << dist[i] << " ";
      
    }
    cout << endl;
  }
  return 0;
}
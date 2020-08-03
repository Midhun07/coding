#include <bits/stdc++.h>
using namespace std;

class UnionFind {
 public:
  UnionFind(int N) {
    p.assign(N, 0); rank.assign(N, 0);
    for (int i = 1; i <= N; i++)
      p[i] = i;
  }
  int findSet(int i) {
    return (p[i] == i) ? i : (p[i] = findSet(p[i]));
  }
  bool isSameSet(int i, int j) {
    return (findSet(i) == findSet(j));
  }
  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) {
      int x = findSet(i); int y = findSet(j);
      if (rank[x] > rank[y]) {
        p[y] = x;
      } else {
        p[x] = y;
        if (rank[x] == rank[y])
          rank[y]++;
      }
    }
  }
 private:
  vector<int> p, rank;
};

int main() {
  vector<pair<int, pair<int, int>>> vp;
  int v = 0, e = 0;
  cin >> v >> e;
  for (int i = 0; i < e; i++) {
    int u = 0, v = 0, w = 0;
    cin >> u >> v >> w;
    vp.push_back(make_pair(w, make_pair(u, v)));
  }
  sort(vp.begin(), vp.end());
  int mst_cost = 0;
  UnionFind uf(v);
  for (int i = 0; i < e; i++) {
    pair<int, int> edge = vp[i].second;
    if (!uf.isSameSet(edge.first, edge.second)) {
      mst_cost += vp[i].first;
      uf.unionSet(edge.first, edge.second);
    }
  }
  cout << mst_cost << endl;
  return 0;
}
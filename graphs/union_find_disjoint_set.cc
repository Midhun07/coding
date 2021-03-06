// template UFDS (Union function disjoint set) OOP style
#include <bits/stdc++.h>
using namespace std;

class UnionFind {
 public:
  UnionFind(int N) {
    p.assign(N, 0); rank.assign(N, 0);
    for (int i = 0; i < N; i++)
      p[i] = i;
  }
  int findSet(int i) {
    return (p[i] == i) ? i : (p[i] = findSet(i));
  }
  bool isSameSet(int i, int j) {
    return (findSet(i) == findSet(j));
  }
  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) {
      int x = findSet(i), y = findSet(j);
      if (rank[x] > rank[y])
        p[y] = x;
      else {
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
  return 0;
}
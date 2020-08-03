#include <bits/stdc++.h>
using namespace std;
#define INF 10000

map<int, vector<int>> mp;
int cost[1001];

void bfs(queue<int> bfs_q) {
    while (!bfs_q.empty()) {
        int u = bfs_q.front();
        bfs_q.pop();
        for (auto e : mp[u]) {
            if (cost[e] == INF) {
                cost[e] = cost[u] + 6;
                bfs_q.push(e);
            }
        }
    }
}

int main() {
    // freopen("in_bfs_cost.txt", "r", stdin);
    int m = 0, n = 0;
    int q = 0;
    cin >> q;
    while (q--) {
        cin >> n >> m;
        memset(cost, 10, sizeof(cost));
        mp.clear();
        queue<int> bfs_q;
        for (int i = 0; i < 1002; i++)
            cost[i] = INF;
        int s = 0;
        for (int i = 0; i < m; i++) {
            int k = 0, l = 0;
            cin >> k >> l;
            mp[k].push_back(l);
            mp[l].push_back(k);
        }
        cin >> s;
        bfs_q.push(s);
        cost[s] = 0;
        bfs(bfs_q);
        for (int i = 1; i <= n; i++)
            if (i == s)
             continue;
            else if (cost[i] == INF)
                cout << -1 << " ";
            else
                cout << cost[i] << " ";
        cout << endl;
    }
    return 0;
}
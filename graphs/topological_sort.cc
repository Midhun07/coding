#include <bits/stdc++.h>
using namespace std;
map<int, vector<int>> mp;
int vis[100] = {0};
vector<int> order;
void dfs(int u) {
    if (vis[u])
        return;
    vis[u] = 1;
    for (auto e : mp[u]) {
        if (!vis[e])
            dfs(e);
    }
    order.push_back(u);
}
int main() {
    int m = 0, n = 0;
    cin >> m >> n;
    while (n--) {
        int l = 0, k = 0;
        cin >> k >> l;
        mp[k].push_back(l);
    }
    for (int i = 1; i <= m; i++)
        if (!vis[i])
            dfs(i);
    for (auto i = order.rbegin(); i != order.rend(); i++)
        cout << *i << " ";
    cout << endl;
    return 0;
}
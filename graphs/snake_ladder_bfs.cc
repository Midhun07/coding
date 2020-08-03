// the key is to have a BFS ready input and then
// doing BFS over the graph

#include <bits/stdc++.h>
using namespace std;
#define INF 10000
int a[110] = {0};
vector<int> p;
queue<int> q;

void process(int i) {
    int prev = p[i] + 1;
    for (int j = 1; j <= 6 && (i + j) <= 100; j++) {
        if (a[i + j] != i + j && min(a[a[i + j]], p[i] + 1) == p[i] + 1) {
            q.push(a[i + j]);
            p[a[i + j]] = a[a[i + j]] = min(a[a[i + j]], p[i] + 1);
        }
        if (a[i + j] < prev) {
            prev = a[i + j] + 1;
        }
        p[i + j] = a[i + j] = min(a[i + j], prev);
    }
    if (i + 6 < 100)
        q.push(i + 6);
}

int main() {
    freopen("in_snake.txt", "r", stdin);
    int m = 0, n = 0, t = 0;
    cin >> t;
    while (t--) { 
        q = queue<int>();   
        int maxl = 0, maxs = 0;
        cin >> m;
        for (int i = 0; i <= 100; i++) {
            a[i] = i;
        }
        while (m--) {
            int l = 0, k = 0;
            cin >> l >> k;
            a[l] = k;
            maxl = max(maxl, k);
        }
        cin >> n;
        while (n--) {
            int l = 0, k = 0;
            cin >> l >> k;
            a[l] = k;
        }
        int flag = 0;
        for (int i = 0; i <= 100; i++) {
            int j;
            if (a[i] < i) {
                flag = 0;
                j = i + 1;
                for (; j <= i + 5; j++) {
                    if (a[j] >= j)
                        flag = j;
                }
                if (!flag)
                    maxs = i + 5;
                i += 6;
            }
        }
        // cout << maxs << endl;
        if (maxl < maxs) {
            cout << -1 << endl;
            continue;
        }
        p.assign(110, 0);
        p[1] = 0;
        int s = 1;
        q.push(s);
        while (!q.empty()) {
            int t = q.front(); q.pop();
            process(t);
        }
        cout << a[100] << endl;
    }
    return 0;
}
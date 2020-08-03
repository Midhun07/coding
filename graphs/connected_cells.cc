#include <bits/stdc++.h>
using namespace std;

int a[10][10] = {0};
int dr[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int flood_fill(int r, int c, int rv, int rc, int m, int n) {
    if (r < 0 || r >= m || c < 0 || c >= n)
        return 0;
    else if (a[r][c] != rv)
        return 0;
    int ans = 1;
    a[r][c] = rc;
    for (int i = 0; i < 8; i++) {
        ans += flood_fill(r + dr[i], c + dc[i], rv, rc, m, n);
    }
    return ans;
}

int main() {
    int m = 0, n = 0;
    int cnt = 0;
    cin >> m;
    cin >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n ; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n ; j++) {
            if (a[i][j] == 1) {
                cnt = max(cnt, flood_fill(i, j, 1, 5, m, n));
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
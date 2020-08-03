#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> subsets;
int ans = 0;
map<int, uint64_t> mp;

void get_subsets(int n, int item, vector<int> vec) {
    if (item == n) {
        int cc = 0;
        int conn = 0;
        for (auto e : vec) {
            if (!(cc & mp[e])) {
                conn++;
            }
            cc = cc | mp[e];
        }
        int set_bits = 0;
        while (cc) {
            if (cc & 1)
                set_bits++;
            cc >>= 1;
        }
        ans += conn + 64 - set_bits;
        return;
    }
    vec.push_back(item);
    get_subsets(n, item+1, vec);
    vec.pop_back();
    get_subsets(n, item+1, vec);
}

int main() {
    // freopen("in_subset_dfs_cc.txt", "r");
    int n = 0;
    cin >> n;
    vector<int> vec;
    for (int i = 0; i < n; i++) {
        uint64_t temp = 0;
        cin >> temp;
        mp[i] = temp;
    }
    get_subsets(n, 0, vec);
    cout << ans << endl;
    return 0;
}
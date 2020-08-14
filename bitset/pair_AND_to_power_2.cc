#include <bits/stdc++.h>
using namespace std;

int main() {
	long a[14] = {0};
	for (int i = 0; i < 14; i++) {
		a[i] = 1 << i;
	}
	int n = 0;
	scanf("%d", &n);
	map<long, int> mp;
	for (int i = 0; i < n; i++) {
		int l = 0; cin >> l;
		for (int j = 0; j < 14; j++) {
			mp[a[j]] += (a[j] & l) ? 1 : 0;
		}
	}
	long ans = 0;
	for (int i = 0; i < 14; i++) {
		ans += (mp[i] * (mp[i] - 1)) / 2;
	}
	cout << ans << endl;
	return 0;
}
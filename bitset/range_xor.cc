#include <bits/stdc++.h>
using namespace std;
long long fun(long long j) {
	int i = j % 8;
	if (i == 0 || i == 1) return j;
	if (i == 2 || i == 3) return 2;
	if (i == 4 || i == 5) return j + 2;
	return 0;
}
int main() {
	int q = 0;
	cin >> q;
	while (q--) {
		long long l = 0, r = 0;
		cin >> l >> r;
		cout << (fun(l - 1) ^ fun(r)) << endl;
	}
	return 0;
}
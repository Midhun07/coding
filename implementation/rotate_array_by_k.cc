#include <bits/stdc++.h>
using namespace std;
unordered_set<int> us;
vector<int> vi;

int main() {
	freopen("in_rotate.txt", "r", stdin);
	int t = 0;
	scanf("%d", &t);
	while (t--) {
		int n = 0, k = 0;
		scanf("%d %d", &n, &k);
		int i = 1;
		while (i <= n) {
			if ((i - k) > 0 && us.find(i - k) == us.end()) {
				us.insert(i - k); vi.push_back(i - k);
			} else if (us.find(k + i) == us.end() && k + i <= n) {
				us.insert(k + i); vi.push_back(k + i);
			} else {
				printf("%d\n", -1);
				vi.clear();
				break;
			}
			i++;
		}
		if (!vi.empty()) {
			for (auto i : vi) printf("%d ", i);
			printf("\n");
		}
		vi.clear(); us.clear();
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
const char yes[4] = "YES";
const char no[3] = "NO";

int main() {
	int t = 0;
	scanf("%d", &t);
	while (t--) {
		int n = 0;
		scanf("%d", &n);
		vector<int> vi;
		vi.assign(n + 1, 0);
		int k = 0;
		while (k < n) {
			scanf("%d", &vi[k++]);
		}
		int i = 0;
		while (i < n-2) {
			if (vi[i] > vi[i + 1]) {
				if (vi[i] > vi[i + 2] && vi[i + 1] < vi[i + 2]) {
					rotate(vi.begin() + i,
						   vi.begin() + i + 1,
						   vi.begin() + i + 2);
				}
				else {
					printf("%s\n", no);
					break;
				}
				i += 2;
			}
			i++;
		}
		if (i == n-1 && vi[i] < vi[i+1] || i > n-1)
			printf("%s\n", yes);
		else
			printf("%s\n", no);
	}
	return 0;
}
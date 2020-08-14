#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define min(x, y) ((x) < (y)) ? (x) : (y)
#define max(x, y) ((x) > (y)) ? (x) : (y)
int main() {
	freopen("in_chess.txt", "r", stdin);
	int n = 0, k = 0;
	scanf("%d %d", &n, &k);
	int r = 0, c = 0;
	scanf("%d %d", &r, &c);
	int ans = 0;
	int ar[8];
	memset(ar, 1, sizeof(ar[0]) * 8);
	ar[0] = min(ar[0], n-r);
	ar[1] = min(ar[1], min(n-r, n-c));
	ar[2] = min(ar[2], n-c);
	ar[3] = min(ar[3], min(n-c, r-1));
	ar[4] = min(ar[4], r-1);
	ar[5] = min(ar[5], min(r-1, c-1));
	ar[6] = min(ar[6], c-1);
	ar[7] = min(ar[7], min(c-1, n-r));
	while (k--) {
		int l = 0, s = 0;
		scanf("%d %d", &l, &s);
		if (s == c && l > r) ar[0] = min(ar[0], max(l-r-1, 0));
		if (l > r && s > c && (l-r == s-c)) ar[1] = min(ar[1], max(l-r-1, 0));
		if (l == r && s > c) ar[2] = min(ar[2], max(s-c-1, 0));
		if (l < r && s > c && (r-l == s-c)) ar[3] = min(ar[3], max(r-l-1, 0));
		if (c == s && l < r) ar[4] = min(ar[4], max(r-l-1, 0));
		if (l < r && s < c && (r-l == c-s)) ar[5] = min(ar[5], max(r-l-1, 0));
		if (l == r && s < c) ar[6] = min(ar[6], max(c-s-1, 0));
		if (l > r && s < c && (l-r == c-s)) ar[7] = min(ar[7], max(l-r-1, 0));
	}
	for (int i = 0; i < 8; i++) {
		ans += ar[i];
	}
		printf("%d\n", ans);
}
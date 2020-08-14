#include <stdio.h>
#include <string.h>
#define test(x) printf("test %d", (x));
int g[1002][1002] = {0};
int p[1002][1002] = {0};
int r = 0, c = 0;
int l = 0, k = 0;

int is_match(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < l && i + x < r; i++) {
		for (int j = 0; j < k && j + y < c; j++) {
			if (g[x + i][y + j] != p[i][j])
				return 0;
		}
	}
	return 1;
}

int main() {
	int t = 0;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &r, &c);
		for (int i = 0; i < r; i++) {
			char str[c];
			scanf("%s", str);
			for (int j = 0; j < c; j++) {
				g[i][j] = str[j] - '0';
			}
		}
		scanf("%d %d", &l, &k);
		for (int i = 0; i < l; i++) {
			char str[c];
			scanf("%s", str);
			for (int j = 0; j < k; j++) {
				p[i][j] = str[j] - '0';
			}
		}
		int flag  = 0;
		for (int i = 0; i + l <= r; i++) {
			for (int j = 0; j + k <= c; j++) {
				if (g[i][j] == p[0][0] && i + (l-1) < r
						&& j + (k-1) < c)
					if (is_match(i, j)) {
						flag = 1;
						break;
					}
			}
			if (flag) break;
		}
		if (flag) printf("%s\n","YES");
		else printf("%s\n", "NO");
		memset(g, 0, sizeof(g[0][0]) * 1002 * 1002);
		memset(p, 0, sizeof(p[0][0]) * 1002 * 1002);
		r = 0; c = 0;
		l = 0; k = 0;
	}
	return 0;
}
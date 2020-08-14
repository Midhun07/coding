#include <stdio.h>
#define min(x, y) ((x) < (y)) ? (x) : (y)

int main() {
	int c = 0, d = 9;
	printf("%d\n", min(c, d));
	return 0;
}
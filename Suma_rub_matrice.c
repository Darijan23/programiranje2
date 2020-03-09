#include <stdio.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

int main() {
	int i, j, m, n, a, s = 0;
	scanf("%d %d ", &n, &m);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d ", &a);
			if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
				s += a;
			}
		}
		scanf(" ");
	}

	printf("%d", s);

	return 0;
}
#include <stdio.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

int main() {
	int n, m, i, j;
	int trans[100][100];
	scanf("%d %d ", &n, &m);

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d ", &trans[j][i]);
		}
	}

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", trans[i][j]);
		}
		printf("\n");
	}

	return 0;
}
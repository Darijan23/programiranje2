#include <stdio.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

void read_matrix(int a[][100], int n) {
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d ", &a[i][j]);
		}
	}
}

void calculate(int a[][100], int n) {
	int i, j, g = 1, d = 1;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i < j) {
				g *= a[i][j];
			} else if (j < i) {
				d *= a[i][j];
			}
		}
	}
	printf("%d %d\n", g, d);
	if (g > d) {
		printf("G");
	} else if (d > g) {
		printf("D");
	} else {
		printf("=");
	}
}

int main() {
	int n;
	int mat[100][100];
	scanf("%d ", &n);

	read_matrix(mat, n);
	calculate(mat, n);

	return 0;
}
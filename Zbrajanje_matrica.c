#include <stdio.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

void sum(int a[][100], int b[][100], int n1, int m1, int n2, int m2) {
	int i, j, c[100][100];
	if (n1 == n2 && m1 == m2) {
		printf("DA\n");
		for (i = 0; i < n1; i++) {
			for (j = 0; j < m1; j++) {
				c[i][j] = a[i][j] + b[i][j];
				printf("%d ", c[i][j]);
			}
			printf("\n");
		}
	} else {
		printf("NE");
	}
}

void input(int a[][100], int b[][100]) {
	int n1, m1, n2, m2, i, j;
	scanf("%d %d ", &n1, &m1);

	for (i = 0; i < n1; i++) {
		for (j = 0; j < m1; j++) {
			scanf("%d ", &a[i][j]);
		}
	}

	scanf("%d %d ", &n2, &m2);

	for (i = 0; i < n2; i++) {
		for (j = 0; j < m2; j++) {
			scanf("%d ", &b[i][j]);
		}
	}

	sum(a, b, n1, m1, n2, m2);
}

int main() {
	int mata[100][100], matb[100][100];
	input(mata, matb);

	return 0;
}
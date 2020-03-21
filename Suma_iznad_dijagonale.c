#include <stdio.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

float suma_dijagonale(float r[][100], int n) {
	int i, j;
	float suma = 0.0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i < j) {
				suma += r[i][j];
			}
		}
	}

	return suma;
}

int main() {
	int n, i, j;
	float mat[100][100];
	scanf("%d ", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%f ", &mat[i][j]);
		}
	}

	printf("%.3f\n", suma_dijagonale(mat, n));

	return 0;
}
#include <stdio.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

float suma_retka(float r[], int n) {
	int i;
	float suma = 0.0;
	for (i = 0; i < n; i++) {
		suma += r[i];
	}

	return suma;
}

int main() {
	int n, m, i, j;
	float mat[100][100];
	scanf("%d %d ", &n, &m);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%f ", &mat[i][j]);
		}
		printf("%.3f\n", suma_retka(mat[i], m));
	}

	return 0;
}
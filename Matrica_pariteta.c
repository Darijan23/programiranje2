#include <stdio.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

typedef struct {
	int m;
	int n;
	int mat[100][100];
	char op;
} parity_matrix;

parity_matrix read_matrix() {
	parity_matrix m;

	scanf("%c %d %d ", &m.op, &m.m, &m.n);

	for (int i = 0; i < m.m; ++i) {
		for (int j = 0; j < m.n; ++j) {
			scanf("%d ", &m.mat[i][j]);
		}
	}

	return m;
}

int parity_bit(int sum, char op) {
	return (sum + (op == 'p' ? 0 : 1)) % 2;
}

void calculate_parity(parity_matrix m) {
	int sum; //body once told me the world was gonna roll me

	for (int i = 0; i < m.m; ++i) {
		sum = 0;
		for (int j = 0; j < m.n; ++j) {
			sum += m.mat[i][j];
		}
		printf("%d ", parity_bit(sum, m.op));
	}

	printf("\n");

	for (int j = 0; j < m.n; ++j) {
		sum = 0;
		for (int i = 0; i < m.m; ++i) {
			sum += m.mat[i][j];
		}
		printf("%d ", parity_bit(sum, m.op));
	}
}

int main() {
	parity_matrix mat;

	mat = read_matrix();

	calculate_parity(mat);

	return 0;
}
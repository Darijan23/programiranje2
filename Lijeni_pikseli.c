#include <stdio.h>
#include <stdlib.h>

#ifndef DEBUG
#define DEBUG(...)printf(__VA_ARGS__)
#endif

int vibecheck(char ***layers, int i, int j) {
	return (
		*(*(*(layers + 0) + i) + j) == *(*(*(layers + 1) + i) + j) || 
		*(*(*(layers + 0) + i) + j) == *(*(*(layers + 2) + i) + j) || 
		*(*(*(layers + 1) + i) + j) == *(*(*(layers + 2) + i) + j)
		);
}

int  main() {
	int m, n, lazy = 0;

	FILE *fp;
	fp = fopen("input.dat", "r");

	fscanf(fp, "%d x %d ", &m, &n);
	char ***layers = malloc(3 * m * sizeof(char *));

	for (int i = 0; i < 3; i++) {
		*(layers + i) = malloc(m * sizeof(char *));
		for (int j = 0; j < m; j++) {
			*(*(layers + i) + j) = malloc(n * sizeof(char));
			fscanf(fp, "%[^\n]\n", *(*(layers + i) + j));
		}
		fscanf(fp, "\n");
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (vibecheck(layers, i, j)) {
				lazy = 1;
				printf("%d %d\n", i, j);
			}
		}
	}

	if (!lazy) {
		printf("NO");
	}

    return 0;
}

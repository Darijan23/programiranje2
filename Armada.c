#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef DEBUG
#define DEBUG(...)printf(__VA_ARGS__)
#endif

int main() {
	int n, rm = 1, sm = 1;
	char **tribine = malloc(sizeof(char *));
	tribine[0] = malloc(sizeof(char));
	memset(tribine[0], ' ', sizeof(char));
	scanf("%d", &n);

	for (int u = 0; u < n; u++) {
		int r, s;
		char c;
		scanf(" %d %d %c", &r, &s, &c);
		if (r > rm - 1) {
			tribine = realloc(tribine, (r + 1) * sizeof(char *));
			for (int i = rm; i <= r; i++) {
				tribine[i] = malloc(sm * sizeof(char));
				memset(tribine[i], ' ', sm * sizeof(char));
			}
			rm = r + 1;
		}

		if (s > sm - 1) {
			for (int i = 0; i < rm; i++) {
				tribine[i] = realloc(tribine[i], (s + 1) * sizeof(char));
				memset(tribine[i] + sm, ' ', (s - sm + 1) * sizeof(char));
			}
			sm = s + 1;
		}
		tribine[r][s] = c;
	}

	for (int i = 0; i < rm; i++) {
		//printf("%s\n", tribine[i]);
		for (int j = 0; j < sm; j++) {
			printf("%c", tribine[i][j]);
		}
		printf("\n");
	}

	return 0;
}
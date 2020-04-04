#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

void vibecheck(char p[], char pdx[][101], int m) {
	int max = 0, maxin = 0;
	for (int i = 0; i < m; ++i) {
		if (strlen(p) == strlen(pdx[i])) {
			int score = 0;
			for (int j = 0; j < strlen(p); ++j) {
				if (p[j] == pdx[i][j] && isalpha(pdx[i][j])) {
					score++;
				}
			}
			if (score > max) {
				max = score;
				maxin = i;
			}
		}
	}
	printf("%s\n", pdx[maxin]);
}

int main() {
	int n, m;
	char unos[100][101];
	char pdx[100][101];
	scanf("%d ", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%s ", unos[i]);
	}

	scanf("%d ", &m);

	for (int i = 0; i < m; ++i) {
		scanf("%s ", pdx[i]);
	}

	for (int i = 0; i < n; ++i) {
		vibecheck(unos[i], pdx, m);
	}

	return 0;
}

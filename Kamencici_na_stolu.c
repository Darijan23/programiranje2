#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

int main() {
	char table[101];
	int van = 0, uvjet = 1, n;
	scanf("%d ", &n);
	scanf("%[^\n]\n", table);

	while (uvjet) {
		int c = 0;
		for (int i = 0; i < strlen(table) - 1; ++i) {
			if (table[i] == table[i + 1]) {
				int j;
				for (j = i; j < strlen(table) - 1; ++j) {
					table[j] = table[j+1];
				}
				table[j] = '\0';
				van++;
				c++;
			}
		}
		if (!c) {
			uvjet = 0;
			break;
		}
	}

	printf("%d", van);

	return 0;
}

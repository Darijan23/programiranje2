#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

#define SIZE 512




int main() {
	int n, j = 0;;
	char niz[SIZE], c1, c2;
	
	scanf("%d ", &n);
	for (int i = 0; i < n; i++) {
		scanf("%c %c ",  &c1, &c2);
		if (isdigit(c1) && isalpha(c2)) {
			niz[j] = c2;
			j++;
		}
	}

	if (j) {
		printf("%s", niz);
	} else {
		printf("EMPTY");
	}

	return 0;
}
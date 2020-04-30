#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

void swap(int *x, int *y);

int main() {
	int c[3], n;
	for (int i = 0; i < 3; i++) {
		scanf("%d ", c + i);
	}

	scanf("%d ", &n);

	for (int i = 0; i < n; i++) {
		int s1, s2;
		scanf("%d %d ", &s1, &s2);
		swap(c + s1 - 1, c +s2 - 1);
	}

	for (int i = 0; i < 3; ++i) {
		if (*(c + i)) {
			printf("%d", i + 1);
		}
	}

	return 0;
}

void swap(int *x, int *y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
#include <stdio.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

int main() {
	int i, n, d = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		if (n % i == 0) {
			d++;
		}
	}
	printf("%d\n", d);

	for (i = 1; i <= n; i++) {
		if (n % i == 0) {
			printf("%d ", i);
		}
	}

	return 0;
}
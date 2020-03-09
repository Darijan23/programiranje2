#include <stdio.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

int main() {
	int i, k, a = 1, b = 0, p;
	scanf("%d", &k);
	for (i = 0; i < k; i++) {
		p = b;
		b += a;
		a = p;
	}
	printf("%d %d", a, b);

	return 0;
}
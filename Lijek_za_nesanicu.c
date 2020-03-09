#include <stdio.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

int main() {
	int i, k, l, m, n, d, s = 0;
	scanf("%d %d %d %d %d ", &k, &l, &m, &n, &d);
	for (i = 1; i <= d; ++i) {
		if (i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0) {
			s++;
		}
	}

	printf("%d", s);

	return 0;
}
#include <stdio.h>
#include <stdint.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

int main() {
	uint8_t a = 0;
	int i, n;
	scanf("%d ", &n);
	n -= 1;

	for (i = 0; i < n; ++i) {
		if (a == 0) {
			a = 1;
		} else {
			a <<= 1;
		}
	}

	printf("%hhu", a);

	return 0;
}
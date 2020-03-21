//Sjebani način

#include <stdio.h>
#include <math.h>
#include <stdint.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

int main() {
	int i, k;
	uint16_t n, b[16];
	scanf("%hi %d ", &n, &k);

	uint8_t mask = 1;

	for (i = k-1; i >= 0; i--) {
		b[i] = n & mask;
		n >>= 1;
	}

	for (i = 0; i < k; ++i) {
		printf("%hi", b[i]);
	}

	return 0;
}
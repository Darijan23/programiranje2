#include <stdio.h>
#include <stdint.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

void print_binary(uint32_t l, int n) {
	uint32_t p = (1 << (n-1));

	while(p != 0) {
		printf("%d", l & p ? 1 : 0);
		p >>= 1;
	}
}

uint32_t create_bitmask(int n) {
	int i;
	uint32_t mask = 0;

	for (i = 0; i < n; ++i) {
		mask <<= 1;
		mask |= 1;
	}

	return mask;
}

uint32_t reverse_binary(uint32_t in, int n) {
	int i;
	uint32_t out = 0;

	for (i = 0; i < n; ++i) {
		out <<= 1;
		out |= in & 1;
		in >>= 1;
	}

	return out;
}

int main() {
	int n, k, i;
	uint32_t l = 0;

	scanf("%d %d ", &n, &k);

	uint32_t mask = create_bitmask(n >> 1);
	l &= mask;

	for (i = 1; i < k % n; i++) {
		if (i <= (n / 2)) {
			l <<= 1;
			l |= 1;
			l &= mask;
		} else {
			l >>= 1;
			l &= mask;
		}
	}

	print_binary(l, n/2);
	print_binary(reverse_binary(l, n/2), n/2);

	return 0;
}
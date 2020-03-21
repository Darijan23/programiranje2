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

int main() {
	int n, i;
	uint32_t l = 0;

	scanf("%d", &n);

	print_binary(l, n);
	printf("\n");

	for (i = 0; i < n; i++) {
		l >>= 1;
		l |= (1 << (n - 1));
		print_binary(l, n);
		printf("\n");
	}

	return 0;
}
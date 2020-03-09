#include <stdio.h>
#include <math.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

int main() {
	int n, b = 0, c = 0;
	scanf("%d", &n);

	while(n > 0) {
		b += (n % 2) * pow(10, c);
		n /= 2;
		c++;
	}

	printf("%d", b);

	return 0;
}
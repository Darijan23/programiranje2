#include <stdio.h>
#include <math.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

int is_prime(int x) {
	int i, c = 0;
	for (i = 2; i <= sqrt(x); i++) {
		if (x % i == 0) {
			c++;
			break;
		}
	}

	if (x == 1 || c)	{
		return 0;
	} else {
		return 1;
	}
}

int main() {
	int a, prosti = 0;

	scanf("%d ", &a);

	while (a != 0) {
		prosti += is_prime(a);
		scanf("%d ", &a);
	}

	printf("%d", prosti);

	return 0;
}
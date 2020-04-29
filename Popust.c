#include <stdio.h>
#include <string.h>
#include <ctype.h>


#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

int *naj(int *a, int *b, int *c) {
	int tmp = *c;
	if (*a > *b && *a > *c)	{
		*c = *a;
		*a = tmp;
	} else if (*b > *a && *b > *c) {
		*c = *b;
		*b = tmp;
	}
	return c;
}

int main() {
	int a, b, c;

	scanf("%d %d %d ", &a, &b, &c);
	printf("%d\n", *naj(&a, &b, &c));
	printf("%d", a + b);

	return 0;
}
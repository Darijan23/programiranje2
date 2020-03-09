#include <stdio.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

int main() {
	int a, b, c;
	scanf("%d %d %d ", &a, &b, &c);

	if ((a + b <= c) || (a + c <= b) || (b + c <= a)) {
		printf("NE");
	} else {
		printf("DA");
	}
	return 0;
}
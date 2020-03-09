#include <stdio.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

int main() {
	int k;
	scanf("%d", &k);

	if (k <= 39) {
		printf("F");
	} else if (k >= 40 && k <= 49) {
		printf("E");
	} else if (k >= 50 && k <= 59) {
		printf("D");
	} else if (k >= 60 && k <= 69) {
		printf("C");
	} else if (k >= 70 && k <= 79) {
		printf("B");
	} else {
		printf("A");
	}
	return 0;
}
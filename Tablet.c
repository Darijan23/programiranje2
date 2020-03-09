#include <stdio.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

int main() {
	int h1, m1, h2, m2, h3 = 0, m3 = 0;
	scanf("%d %d\n %d %d ", &h1, &m1, &h2, &m2);
	h3 = ((h2 * 60 + m2) - (h1 * 60 + m1)) / 60;
	m3 = ((h2 * 60 + m2) - (h1 * 60 + m1) )- (h3 * 60);
	printf("%d %d", h3, m3);
	
	return 0;
}
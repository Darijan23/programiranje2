#include <stdio.h>
#include <stdint.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

int main() {
	char o;
	int8_t c;
	int16_t a, b;
	scanf("%c ", &o);
	scanf("%hi %hi ", &a, &b);

	switch(o) {
		case '&':
			c = a & b;
			break;

		case '|':
			c = a | b;
			break;

		case '^':
			c = a ^ b;
			break;

		case '<':
			c = a << b;
			break;

		case '>':
			c = a >> b;
			break;

	}

	printf("%hhi", c);


	return 0;
}
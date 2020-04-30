#include <stdio.h>
#include <ctype.h>
#include <math.h>


#ifndef DEBUG
#define DEBUG(...)printf(_VA_ARGS_)
#endif

float stringtofloat(char *s);

int main() {
	int n;
	char str[256];

	scanf("%d ", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		printf("%.03f\n", stringtofloat(str));
	}

	return 0;
}

float stringtofloat(char *s) {
	int pre = 1;
	float out = 0;

	if (*s == '-') {
		pre = 0;
		s++;
	}

	while(*s != '.') {
		out *= 10;
		out += *s - '0';
		s++;
	}
	s++;
	int p =-1;
	while(*s) {
		out += (*s - '0') * pow(10, p);
		p--;
		s++;
	}

	if (!pre) {
		return out * (-1);
	}
	return out;
}
#include <stdio.h>
#include <string.h>
#include <ctype.h>


#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

void decypher(char *S, int *B);

int main() {
	char S[100];
	int B = 0;

	scanf("%s", S);
	decypher(S, &B);

	return 0;
}

void decypher(char *S, int *B) {
	while(*S) {
		int tmp = 0;
		while(isdigit(*S)) {
			tmp *= 10;
			tmp += *S - '0';
			S++;
		}
		*B += tmp;
		S++;
	}
	printf("%d", *B);
}
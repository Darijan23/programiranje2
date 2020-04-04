#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

int main() {
	char track[101];
	scanf("%[^\n]\n", track);
	if (strlen(strchr(track, 'P')) < strlen(strchr(track, 'M')))	{
		printf("Princeza\n");
		printf("%ld", strlen(strchr(track, 'P')) - 1);
	} else {
		printf("Mario\n");
		printf("%ld", strlen(strchr(track, 'M')) - 1);
	}

	return 0;
}

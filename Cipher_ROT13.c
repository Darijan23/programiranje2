#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

char cipher(char c) {
	if ((c <= 'M' && c >= 'A' )|| (c <= 'm' && c >= 'a')) {
		c += 13;
	} else {
		c -= 13;
	}
	return c;
}

int main() {
	char line[512];

	FILE *fin;
	fin = fopen("input.dat", "r");
	FILE *fout;
	fout = fopen("decrypted.txt", "w+");

	while (!feof(fin)) {
		fscanf(fin, "%[^\n]\n", line);
		for (int i = 0; i < strlen(line); ++i) {
			if (isalpha(line[i]))	{
				line[i] = cipher(line[i]);
			}
			fprintf(fout, "%c", line[i]);
			printf("%c", line[i]);
		}
		fprintf(fout, "\n");
		printf("\n");
	}

	fclose(fin);
	fclose(fout);

	return 0;
}
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

int ispali(char in[]) {
	int n = strlen(in);
	for (int i = 0; i < n; i++) {
		in[i] = tolower(in[i]);
		if (!isalpha(in[i])) {
			int j;
			for (j = i; j < n; j++) {
				in[j] = in[j + 1];
			}
			n--;
			i--;
		}
	}
	in[n] = '\0';

	char rev[n + 1];
	for (int i = 0; i < n + 1; ++i) {
		rev[i] = '\0';
	}

	int j = 0;
	for (int i = strlen(in) - 1; i >= 0; i--) {
		rev[j] = in[i];
		j++;
	}

	return !strcmp(in, rev);
}
	
int main() {
	char line[256];
	int c = 0;

	FILE *fp;
	fp = fopen("input.dat", "r");

	while (!feof(fp)) {
		fscanf(fp, "%[^\n]\n", line);
		c += ispali(line);
	}

	printf("%d", c);

	fclose(fp);

	return 0;
}
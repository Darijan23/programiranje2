#include <stdio.h>
#include <string.h>
#include <ctype.h>


#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif


int main() {
	char line[128];
	int w, h, d, i;

	FILE *fp;
	fp = fopen("input.dat", "r");

	fscanf(fp, "%[^\n]\n", line);

	if (strcmp(line, "P2")) {
		printf("NE");
	} else {
		fscanf(fp, "%d %d %d ", &w, &h, &d);
		int pix[256] = {0};
		while (!feof(fp)) {
			fscanf(fp, "%d ", &i);
			pix[i]++;
		}

		for (int i = 0; i < d + 1; ++i) {
			printf("%d ", pix[i]);
		}
	}

	return 0;
}
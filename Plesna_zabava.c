#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

typedef struct {
	char ime[32];
	int br;
} dancer;

int dancomp(dancer d1, dancer d2) {
	if (d1.br == d2.br) {
		return strcmp(d1.ime, d2.ime);
	}
	return d1.br < d2.br;
}

void strcorr(char str[]) {
	str[0] = toupper(str[0]);
	for (int i = 1; i < strlen(str); i++) {
		if (!isalpha(str[i])) {
			str[i] = str[i + 1];
		}
		str[i] = tolower(str[i]);
	}
}

void sort(dancer ples[], int n) {
	for (int i = 0; i < n; i++) {
		dancer temp = ples[i];
		int j = i;

		while (j > 0 && dancomp(ples[j - 1], temp) > 0) {
			ples[j] = ples[j - 1];
			j--;
		}
		ples[j] = temp;
	}
}

int main() {
	int n;
	dancer ples[10];

	FILE *fin, *fout;
	fin = fopen("input.dat", "r");
	fout = fopen("output.dat", "w");

	scanf("%d ", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s ", ples[i].ime);
		strcorr(ples[i].ime);
		ples[i].br = 0;
	}

	while (!feof(fin)) {
		char ime[32];
		fscanf(fin, "%s ", ime);
		strcorr(ime);
		for (int i = 0; i < n; ++i) {
			if (!strcmp(ime, ples[i].ime)) {
				ples[i].br++;
			}
		}
	}

	sort(ples, n);

	for (int i = 0; i < n; i++) {
		printf("%s %d\n", ples[i].ime, ples[i].br);
		fprintf(fout, "%s %d\n", ples[i].ime, ples[i].br);
	}

	fclose(fin);
	fclose(fout);

	return 0;
}
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

typedef struct {
	char name[64];
	int price;
	int sold;
} stock;

void strfix(char in[]) {
	int i, n = 0;

	for (i = 0; i < strlen(in); i++) {
		in[i - n] = toupper(in[i]);
		if (!isalpha(in[i]) && in[i - n] != '-') {
			n++;
		}
	}
	in[i - n] = '\0';
}

int stkcomp(stock s1, stock s2) {
	if (s1.sold * s1.price == s2.sold * s2.price) {
		return strcmp(s1.name, s2.name);
	}
	return s1.sold * s1.price < s2.sold * s2.price;
}

void sort(stock s[], int n) {
	for (int i = 1; i < n; ++i) {
		stock temp = s[i];
		int j = i;

		while (j > 0 && stkcomp(s[j - 1], temp) > 0) {
			s[j] = s[j - 1];
			j--;
		}
		s[j] = temp;
	}
}

int main() {
	int n, brs = 0;
	char line[128];
	stock stonks[1000];

	FILE *fin, *fout;
	fin = fopen("input.dat", "r");
	fout = fopen("output.dat", "w");

	do {
		scanf("%[^\n]\n", line);
		sscanf(line, "%s %d", stonks[brs].name, &stonks[brs].price);
		strfix(stonks[brs].name);
		stonks[brs].sold = 0;
		brs++;
	} while(line[0] != '-');
	brs--;

	fscanf(fin, "%d ", &n);

	for (int i = 0; i < n; i++) {
		char tmp[32], stonk[64];
		int sold;
		fscanf(fin, "%s %s %d", tmp, stonk, &sold);
		for (int j = 0; j < brs; j++) {
			strfix(stonk);
			if (!strcmp(stonk, stonks[j].name)) {
				stonks[j].sold += sold;
			}
		}
	}

	sort(stonks, brs);

	for (int i = 0; i < brs; ++i) {
		if (stonks[i].sold) {
			printf("%s %d %d %d\n", stonks[i].name, stonks[i].sold, stonks[i].price, stonks[i].sold * stonks[i].price);
			fprintf(fout, "%s %d %d %d\n", stonks[i].name, stonks[i].sold, stonks[i].price, stonks[i].sold * stonks[i].price);
		}
	}

	fclose(fin);
	fclose(fout);

	return 0;
}
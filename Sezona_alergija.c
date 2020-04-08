#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif


typedef struct {
	char ime[128], prezime[128];
	char email[128];
	char isal[3];
	int startm, endm;
} pacijent;

int paccomp(pacijent p1, pacijent p2) {
	if (!strcmp(p1.prezime, p2.prezime)) {
		return strcmp(p1.ime, p2.ime);
	}
	return strcmp(p1.prezime, p2.prezime);
}

void sort(pacijent in[], int n) {
	for (int i = 1; i < n; ++i) {
		pacijent temp = in[i];
		int j = i;

		while (j > 0 && paccomp(in[j - 1], temp) > 0) {
			in[j] = in[j - 1];
			j--;
		}
		in[j] = temp;
	}
}

void printpac(pacijent in) {
	printf("%s, %s: %s\n", in.prezime, in.ime, in.email);
}

void corrector(char in[]) {
	in[0] = toupper(in[0]);
	for (int i = 1; i < strlen(in); ++i) {
		in[i] = tolower(in[i]);
	}
}


int main() {
	pacijent pacs[1000];
	int n, d, m, y;

	scanf("%d ", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%s %s %s %2s ", pacs[i].ime, pacs[i].prezime, pacs[i].email, pacs[i].isal);
		corrector(pacs[i].ime);
		corrector(pacs[i].prezime);
		if (pacs[i].isal[0] == 'D') {
			scanf("%d %d ", &pacs[i].startm, &pacs[i].endm);
		}
	}

	sort(pacs, n);

	scanf("%d.%d.%d ", &d, &m, &y);

	for (int i = 0; i < n; ++i) {
		if (pacs[i].startm <= m && pacs[i].endm >= m) {
			printpac(pacs[i]);
		}
		
	}	

	return 0;
}

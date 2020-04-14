#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

#define MAX 100


typedef struct {
	char ime[MAX];
	int kol;
} sastojak;

typedef struct {
	char ime[MAX];
	sastojak sas[50];
} recept;


void sort(sastojak s[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (strcmp(s[j - 1].ime, s[j].ime) > 0) {
				sastojak tmp = s[j - 1];
				s[j - 1] = s[j];
				s[j] = tmp;
			}
		}
	}
}

int main() {
	recept kolac;
	sastojak sastojci[50];
	char line[MAX];
	int dovoljno[50] = {0}, moze = 1;
	int brojrec = 0, brojsas = 0; //brojrec - broj sastojaka potrebnih, brojsas - broj dostupnih sastojaka

	scanf("%[^\n] ", kolac.ime);
	
	FILE *fp;
	fp = fopen("input.dat", "r");

	while (!feof(fp)) {
		fscanf(fp, "%[^\n] ", line);

		if (!strcmp(line, kolac.ime)) {
			do {
				fgets(line, MAX, fp);
				sscanf(line, "%[^,], %d ", kolac.sas[brojrec].ime, &kolac.sas[brojrec].kol);
				brojrec++;
			} while (line[0] != '-');
		}
	}
	brojrec--;

	sort(kolac.sas, brojrec);
	
	do {
		scanf("%[^\n]\n", line);
		sscanf(line, "%[^,], %d\n", sastojci[brojsas].ime, &sastojci[brojsas].kol);
		brojsas++;
	} while (line[0] != '-');
	brojsas--;


	for (int i = 0; i < brojrec; i++) {
		for (int j = 0; j < brojsas; j++) {
			if (!strcmp(kolac.sas[i].ime, sastojci[j].ime)) {
				if (sastojci[j].kol >= kolac.sas[i].kol) {
					dovoljno[i] = 1;
				} else {
					kolac.sas[i].kol -= sastojci[j].kol;
					moze = 0;
				}
			}
		}
		if (!dovoljno[i]) {
			moze = 0;
		}
	}


	if (moze) {
		printf("DA");
	} else {
		printf("NE\n");
		for (int i = 0; i < brojrec; i++) {
			if (!dovoljno[i]) {
				printf("%s, %d\n", kolac.sas[i].ime, kolac.sas[i].kol);
			}
		}
	}

	fclose(fp);

	return 0;
}
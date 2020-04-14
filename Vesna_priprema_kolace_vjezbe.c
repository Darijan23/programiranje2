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

int provjeri(int nrec, int p[]) {
	for (int i = 0; i < nrec; ++i) {
		if (!p[i]) {
			return 0;
		}
	}
	return 1;
}

int main() {
	sastojak recept[MAX], s[MAX];
	char rec[MAX], tmp[MAX];
	int p[MAX] = {0};
	int nrec = 0, ns = 0;

	FILE *fp;

	fp = fopen("input.dat", "r");

	fgets(rec, MAX, stdin);

	while (!feof(fp)) {
		fgets(tmp, MAX, fp);

		if (!strcmp(tmp, rec)) {
			fgets(tmp, MAX, fp);
			sscanf(tmp, "%[^,], %d ", recept[nrec].ime, &recept[nrec].kol);

			while (tmp[0] != '-') {
				nrec++;
				fgets(tmp, MAX, fp);
				sscanf(tmp, "%[^,], %d ", recept[nrec].ime, &recept[nrec].kol);
			}
		}
	}

	sort(recept, nrec);

	fgets(tmp, MAX, stdin);

	while (tmp[0] != '-') {
		sscanf(tmp, "%[^,], %d ", s[ns].ime, &s[ns].kol);
		fgets(tmp, MAX, stdin);
		ns++;
	}

	for (int i = 0; i < nrec; ++i) {
		for (int j = 0; j < ns; ++j) {
			if (!strcmp(s[j].ime, recept[i].ime) && recept[i].kol <= s[j].kol) {
				p[i] = 1;
			} else if (!strcmp(s[j].ime, recept[i].ime)) {
				recept[i].kol -= s[j].kol;
			}
		}
	}

	if (provjeri(nrec, p)) {
		printf("DA");
	} else {
		printf("NE\n");
		for (int i = 0; i < nrec; ++i) {
			if (!p[i]) {
				printf("%s, %d\n", recept[i].ime, recept[i].kol);
			}
		}
	}

	fclose(fp);

	return 0;
}

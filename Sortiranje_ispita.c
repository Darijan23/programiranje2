#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif


typedef struct {
	char ime[128], prezime[128];
	int bodovi, zadaci[100];
} student;

int stcmp(student s1, student s2) {
	if (s1.bodovi == s2.bodovi) {
		if (!strcmp(s1.prezime, s2.prezime)) {
			return strcmp(s1.ime, s2.ime);
		} else {
			return strcmp(s1.prezime, s2.prezime);
		}
	} 
	return s1.bodovi < s2.bodovi;
}


void sort(student in[], int n) {
	for (int i = 1; i < n; ++i) {
		student temp = in[i];
		int j = i;

		while (j > 0 && stcmp(in[j - 1], temp) > 0) {
			in[j] = in[j - 1];
			j--;
		}
		in[j] = temp;
	}
}


int main() {
	int z, n;
	int bod[100];
	student sts[100];

	scanf("%d ", &z);
	for (int i = 0; i < z; ++i) {
		scanf("%d ", &bod[i]);
	}

	scanf("%d ", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%s %s ", sts[i].ime, sts[i].prezime);
		sts[i].bodovi = 0;
		for (int j = 0; j < z; ++j) {
			scanf("%d ", &sts[i].zadaci[j]);
			if (sts[i].zadaci[j]) {
				sts[i].bodovi += bod[j];
			}
		}
	}

	sort(sts, n);

	for (int i = 0; i < n; ++i) {
		printf("%s %s %d\n", sts[i].ime, sts[i].prezime, sts[i].bodovi);
	}

	return 0;
}

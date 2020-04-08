#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif


typedef struct {
	char ime[128], prezime[128];
} student;

int stcmp(student s1, student s2) {
	if (!strcmp(s1.prezime, s2.prezime)) {
		return strcmp(s1.ime, s2.ime);
	}
	return strcmp(s1.prezime, s2.prezime);
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
	int n;
	student sts[30];
	
	scanf("%d ", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%s %s ", sts[i].ime, sts[i].prezime);
	}

	sort(sts, n);

	for (int i = 0; i < n; ++i) {
		printf("%d %s %s\n", i+1, sts[i].ime, sts[i].prezime);
	}
	

	return 0;
}

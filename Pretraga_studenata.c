#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

typedef struct {
	int d, m, y;
} date;

typedef struct {
	int jmbag;
	char ime[128], prezime[128];
	date rod;
} student;

void sort(student in[], int n) {
	for (int i = 1; i < n; ++i) {
		student temp = in[i];
		int j = i;

		while (j > 0 && in[j - 1].jmbag > temp.jmbag)  {
			in[j] = in[j - 1];
			j--;
		}
		in[j] = temp;
	}
}

void printst(student in) {
	printf("%010d %s %s %d.%d.%d.\n", in.jmbag, in.prezime, in.ime, in.rod.d, in.rod.m, in.rod.y);
}

int main() {
	student sts[1000];
	char line[256];
	int n, m;

	scanf("%d ", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%[^\n]\n", line);
		sscanf(line, "%d %s %s %d.%d.%d.", &sts[i].jmbag, sts[i].ime, sts[i].prezime, &sts[i].rod.d, &sts[i].rod.m, &sts[i].rod.y);
	}

	sort(sts, n);

	scanf("%d ", &m);

	for (int i = 0; i < m; ++i) {
		char f;
		int jmbag, c = 0;
		char ime[256];
		scanf("%c ", &f);
		switch (f) {
			case 'J':
				scanf("%d ", &jmbag);
				printf("JMBAG: %010d\n", jmbag);
				for (int j = 0; j < n; ++j) {
					if (sts[j].jmbag == jmbag) {
						printst(sts[j]);
						c++;
					}
				}

				if (!c) {
					printf("-\n");
				}
			break;

			case 'I':
				scanf("%s\n", ime);
				printf("Ime: %s\n", ime);
				for (int j = 0; j < n; ++j) {
					if (!strcmp(ime, sts[j].ime)) {
						printst(sts[j]);
						c++;
					}
				}
				
				if (!c) {
					printf("-\n");
				}
			break;

			case 'P':
				scanf("%s\n", ime);
				printf("Prezime: %s\n", ime);
				for (int j = 0; j < n; ++j) {
					if (!strcmp(ime, sts[j].prezime)) {
						printst(sts[j]);
						c++;
					}
				}
				
				if (!c) {
					printf("-\n");
				}
			break;
		}
	}	

	return 0;
}

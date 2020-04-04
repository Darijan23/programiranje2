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
	char ime[128], prezime[128];
	date rod;
} student;

int datcomp(date d1, date d2) {
	if (d2.y == d1.y) {
		if (d2.m == d1.m) {
			if (d2.d <= d1.d) {
				return 1;
			} else {
				return -1;
			}
		} else if (d2.m < d1.m) {
			return 1;
		} else {
			return -1;
		}
	} else if (d2.y < d1.y)	{
		return 1;
	}
	return -1;
}

int stucomp(student s1, student s2) {
	if (!strcmp(s1.prezime, s2.prezime)) {
		if (!strcmp(s1.ime, s2.ime)) {
			return datcomp(s1.rod, s2.rod);
		} else {
			return strcmp(s1.ime, s2.ime);
		}
	}
	return strcmp(s1.prezime, s2.prezime);
}

void sort(student in[], int n) {
	for (int i = 1; i < n; ++i) {
		student temp = in[i];
		int j = i;

		while (j > 0 && stucomp(in[j - 1], temp) > 0) {
			in[j] = in[j - 1];
			j--;
		}
		in[j] = temp;
	}
}

int main() {
	student sts[1000];
	char line[256];
	int n;
	scanf("%d ", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%[^\n]\n", line);
		sscanf(line, "%s %s %d.%d.%d.", sts[i].ime, sts[i].prezime, &sts[i].rod.d, &sts[i].rod.m, &sts[i].rod.y);
	}

	sort(sts, n);
	
	for (int i = 0; i < n; ++i)	{
		printf("%s;%s;%d.%d.%d\n", sts[i].prezime, sts[i].ime, sts[i].rod.d, sts[i].rod.m, sts[i].rod.y);

	}

	return 0;
}

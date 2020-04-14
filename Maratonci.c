#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

#define LEN 42195
#define MAX 256

typedef struct {
	int h, m, s;
} time;

typedef struct {
	char ime[MAX];
	char prezime[MAX];
	char p[32];
	time t;
	float v;
} comp;

int tosec(time t) {
	return t.h * 3600 + t.m * 60 + t.s;
}

float compvel(comp m) {
	return (float)LEN / tosec(m.t);
}

int natcmp(comp c1, comp c2) {
	if (c1.v == c2.v) {
		if (!strcmp(c1.prezime, c2.prezime)) {
			return strcmp(c1.ime, c2.ime);
		} else {
			return strcmp(c1.prezime, c2.prezime);
		}
	} 
	return c1.v < c2.v;
}

void sort(comp in[], int n) {
	for (int i = 1; i < n; ++i) {
		comp temp = in[i];
		int j = i;

		while (j > 0 && natcmp(in[j - 1], temp) > 0) {
			in[j] = in[j - 1];
			j--;
		}
		in[j] = temp;
	}
}


int main() {
	float pavg = 0.0, ravg = 0.0;
	comp rek[256], pro[256], curr;
	int p = 0, r = 0;

	FILE *fp;
	fp = fopen("input.dat", "r");

	while (!feof(fp)) {
		fscanf(fp, "%s %[^,], %[^:]: %d:%d:%d\n", curr.ime, curr.prezime, curr.p, &curr.t.h, &curr.t.m, &curr.t.s);
		curr.v = compvel(curr);
		if (curr.p[0] == 'p') {
			pro[p] = curr;
			p++;
			pavg += curr.v;
		} else {
			rek[r] = curr;
			r++;
			ravg += curr.v;
		}
	}

	if (p) {
		pavg /= p;
		sort(pro, p);
	}
	if (r) {
		ravg /= r;
		sort(rek, r);
	}


	printf("Profesionalci:\n");
	for (int i = 0; i < p; i++) {
		if (pro[i].v > pavg) {
			printf("\t%s %s %.2f\n", pro[i].ime, pro[i].prezime, pro[i].v);
		}
	}

	printf("Rekreativci:\n");
	for (int i = 0; i < r; i++) {
		if (rek[i].v > ravg) {
			printf("\t%s %s %.2f\n", rek[i].ime, rek[i].prezime, rek[i].v);
		}
	}

	fclose(fp);

	return 0;
}
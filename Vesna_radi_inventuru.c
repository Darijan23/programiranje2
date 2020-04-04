#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

typedef struct {
	int before;
	int after;
	int sold;
	int barcode;
	char name[128];
	char grade[128];
} product;

product scan(char line[]) {
	product p;
	sscanf(line, "%[^|] | %d | %d", p.name, &p.barcode, &p.before);
	p.after = 0;
	p.sold = 0;
	p.grade[0] = '\0';

	return p;
}

void inc_num(product p[], int size, int brcd, int num) {
	for (int i = 0; i < size; ++i) {
		if (p[i].barcode == brcd) {
			p[i].after += num;
			break;
		}
	}
}

void calc_sold(product p[], int size) {
	for (int i = 0; i < size; i++) {
		p[i].sold = p[i].before - p[i].after;
		if ((float)p[i].sold >= 0.8 * p[i].before) {
			strcat(p[i].grade, "*****");
		} else if ((float)p[i].sold >= 0.6 * p[i].before) {
			strcat(p[i].grade, "****");
		} else if ((float)p[i].sold >= 0.4 * p[i].before) {
			strcat(p[i].grade, "***");
		} else if ((float)p[i].sold >= 0.2 * p[i].before) {
			strcat(p[i].grade, "**");
		} else {
			strcat(p[i].grade, "*");
		}
	}
}

void sort(product p[], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 1; j < size; j++) {
			if (strcmp(p[j - 1].name, p[j].name) > 0) {
				product tmp = p[j - 1];
				p[j - 1] = p[j];
				p[j] = tmp;
			}
		}
	}
}

void print(product p[], int size) {
	printf("%-35s | %-8s | %-8s | %-8s |\n", "Ime:", "Prije:", "Poslije:", "Prodano:");
	for (int i = 0; i < size; i++)	{
		printf("%-35s | %8d | %8d | %8d | %s\n", p[i].name, p[i].before, p[i].after, p[i].sold, p[i].grade);
	}
}

int main() {
	product p[500];
	char line[256];
	int size = 0, num, brcd;

	scanf(" %[^\n]\n", line);

	while (line[0] != '-') {
		p[size] = scan(line);
		size++;

		scanf(" %[^\n]\n", line);
	}

	scanf("%d x %d", &num, &brcd);

	while (num && brcd) {
		inc_num(p, size, brcd, num);
		scanf("%d x %d", &num, &brcd);
	}

	calc_sold(p, size);
	sort(p, size);

	print(p, size);

	return 0;
}
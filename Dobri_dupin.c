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
	char name[32];
	int scars;
	int len;
	int num;
	date javljanja[2];
} dupin;

int isleap(int y) {
	if (!(y % 100) && !(y % 400)) {
		return 1;
	} else if (!(y % 4) && (y % 100)) {
		return 1;
	}
	return 0;
}

date newer(date d1, date d2) {
	if (d1.y == d2.y) {
		if (d1.m == d2.m) {
			if (d1.d > d2.d) {
				return d1;
			} else {
				return d2;
			}
		} else if (d1.m > d2.m) {
			return d1;
		} else {
			return d2;
		}
	} else if (d1.y > d2.y) {
		return d1;
	}
	return d2;
}

date older(date d1, date d2) {
	if (d1.y == d2.y) {
		if (d1.m == d2.m) {
			if (d1.d > d2.d) {
				return d2;
			} else {
				return d1;
			}
		} else if (d1.m > d2.m) {
			return d2;
		} else {
			return d1;
		}
	} else if (d1.y > d2.y) {
		return d2;
	}
	return d1;
}

int diff(date d1, date d2) {
	int n = 0;
	int mon[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  	while (d1.d != d2.d || d1.m != d2.m || d1.y != d2.y) {
  		//printf("%d.%d.%d.\n", d1.d, d1.m, d1.y);
    	d1.d++;

    	if (d1.d > mon[d1.m] + (d1.m == 2 && !isleap(d1.y))) {
        	d1.m++;
        	d1.d = 1;
    	}

    	if (d1.d > 29 && (d1.m == 2 && isleap(d1.y))) {
        	d1.m++;
        	d1.d = 1;
    	}

    	if (d1.m > 12) {
    	    d1.m = 1;
    	    d1.y++;
    	}

    	n++;
  	}
	return n;
}

int main() {
	int n, d, br = 0, pop = 0;
	dupin populacija[100];
	date dan;

	FILE *fp;
	fp = fopen("input.dat", "r");

	fscanf(fp, "%d %d ", &d, &n);

	for (int i = 0; i < d; i++) {
		dupin temp;
		fscanf(fp, "%d %d %d.%d.%d. ", &temp.scars, &temp.len, &temp.javljanja[0].d, &temp.javljanja[0].m, &temp.javljanja[0].y);
		int postoji = 0;
		for (int j = 0; j < br; j++) {
			if (temp.scars == populacija[j].scars && temp.len == populacija[j].len) {
				postoji = 1;
				populacija[j].javljanja[0] = older(populacija[j].javljanja[0], temp.javljanja[0]);
				populacija[j].javljanja[1] = newer(populacija[j].javljanja[1], temp.javljanja[0]);
			}
		}

		if (!postoji) {
			fscanf(fp, "%s", temp.name);
			temp.javljanja[1] = temp.javljanja[0];
			populacija[br] = temp;
			br++;
		}
	}
	
	fscanf(fp, " %d.%d.%d. ", &dan.d, &dan.m, &dan.y);

	for (int i = 0; i < br; i++)
	{
		if (diff(populacija[i].javljanja[1], dan) < n) {
			pop++;
		}
	}
	printf("%d\n", pop);

	for (int i = 0; i < br; i++)
	{
		if (diff(populacija[i].javljanja[1], dan) < n) {
			printf("%s %d %d %d.%d.%d. %d.%d.%d.\n", populacija[i].name, populacija[i].scars, populacija[i].len, populacija[i].javljanja[0].d, populacija[i].javljanja[0].m, populacija[i].javljanja[0].y, populacija[i].javljanja[1].d, populacija[i].javljanja[1].m, populacija[i].javljanja[1].y);
		}
	}

	return 0;
}
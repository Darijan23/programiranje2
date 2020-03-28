#include <stdio.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

typedef struct {
	int d, m, y;
} datum;

datum add(datum d, int n) {
	datum out;
	out.d = d.d;
	out.m = d.m;
	out.y = d.y;
	while (n > 0) {
		if (((out.m % 2) && out.m <= 7) || ((out.m % 2 == 0) && out.m > 7)) {
			while (n > 0 && out.d < 31) {
				out.d++;
				n--;
			}
			if (out.d == 31 && n > 0) {
				if (out.m != 12) {
					out.d = 1;
					out.m++;
				} else {
					out.y++;
					out.d = 1;
					out.m = 1;
				}
				n--;
			}
		} else if (((out.m % 2) && (out.m > 8)) || ((out.m % 2 == 0) && (out.m <= 7) && out.m != 2)) {
			while (n > 0 && out.d < 30) {
				out.d++;
				n--;
			}
			if (out.d == 30 && n > 0) {
				out.d = 1;
				out.m++;
				n--;
			}
		} else if (out.m == 2) {
			if (out.y % 4) {
				while (n > 0 && out.d < 28) {
				out.d++;
				n--;
				}
				if (out.d == 28 && n > 0) {
					out.d = 1;
					out.m++;
					n--;
				}
			} else {
				while (n > 0 && out.d < 29) {
				out.d++;
				n--;
				}
				if (out.d == 29 && n > 0) {
					out.d = 1;
					out.m++;
					n--;
				}
			}
		}
	}
	return out;
}

int main() {
	int n;
	datum dan;
	scanf("%d ", &n);
	scanf("%d.%d.%d. ", &dan.d, &dan.m, &dan.y);
	datum out = add(dan, n);
	printf("%d.%d.%d.", out.d, out.m, out.y);

	return 0;
}
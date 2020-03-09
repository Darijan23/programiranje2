#include <stdio.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

int main() {
	int i, j, n, p, q, uvjet = 0, broj = 0;
	int x[100], y[100];
	scanf("%d %d ", &n, &p);
	for (i = 0; i < p; i++) {
		scanf("%d ", &x[i]);
	}

	scanf("%d ", &q);
	for (i = 0; i < q; i++) {
		scanf("%d ", &y[i]);
	}

	for (i = 1; i <= n; i++) {
		uvjet = 0;
		for (j = 0; j < p; j++) {
			if (x[j] == i) {
				uvjet = 1;
				break;
			}
		}

		if (!uvjet)	{
			for (j = 0; j < q; j++) {
				if (y[j] == i) {
					uvjet = 1;
					break;
				}
			}
		}

		if (uvjet) {
			broj++;
		}
	}

	if (broj == n) {
		printf("I become the guy.");
	} else {
		printf("Oh, my keyboard!");
	}

	return 0;
}
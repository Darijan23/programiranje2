#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef DEBUG
#define DEBUG(...)printf(__VA_ARGS__)
#endif

int jump(int c, int n, int d, int k, int t, int *tram, int p, int * pok) {
	if (c == n)	{
		return 1;
	} else if (c > n) {
		return 0;
	}

	int var = 0;

	if (*(pok + c)) {
		return 0;
	} else if (*(tram + c)) {
		var += jump(c + k, n, d, k, t, tram, p, pok);
	} else {
		for (int i = 1; i <= d; i++) {
			var += jump(c + i, n, d, k, t, tram, p, pok);
		}
	}

	return var;
}

int main(void) {
	int n, d, k, t, tram[35] = {0}, p, pok[35] = {0};

	scanf("%d %d %d %d", &n, &d, &k, &t);
	for (int i = 0; i < t; i++) {
		int temp;
		scanf("%d ", &temp);
		*(tram + temp) = 1;
	}

	scanf("%d ", &p);

	for (int i = 0; i < p; i++) {
		int temp;
		scanf("%d ", &temp);
		*(pok + temp) = 1;
	}

	printf("%d", jump(1, n, d, k, t, tram, p, pok));

	return 0;
}
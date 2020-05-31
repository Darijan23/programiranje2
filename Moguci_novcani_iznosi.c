#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef DEBUG
#define DEBUG(...)printf(__VA_ARGS__)
#endif

int vibecheck(int val, int n, int m, int *v, int *pos) {
	int vals = 1;
	if (val > m || *(pos + val)) {
		return 0;
	}

	*(pos + val) = 1;

	for (int i = 0; i < n; i++) {
		vals += vibecheck(val + *(v + i), n, m, v, pos);
	}

	return vals;
}

int main(void) {
	int n, m, *v, *pos, tot = 0;
	scanf("%d %d ", &n, &m);
	v = malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		scanf("%d ", v + i);
	}

	pos = malloc((m + 1) * sizeof(int));
	memset(pos, 0, (m + 1) * sizeof(int));

	tot = vibecheck(0, n, m, v, pos);

	printf("%d", tot);

    return 0;
}

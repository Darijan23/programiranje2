#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

int broj_elemenata(int a[][20], int *gl, int *dd) {
	//WHAT
	//THE
	//ACTUAL
	int f, u, k;

	f = sizeof(a[0]) / sizeof(a[0][0]);
	u = ((dd - gl) / f) + 1;
	k = ((dd - gl) % f) + 1;

	return u * k;
}

int main() {
  int q, i1, j1, i2, j2, a[10][20];
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    scanf("%d%d%d%d", &i1, &j1, &i2, &j2);
    printf("%d\n", broj_elemenata(a, &a[i1][j1], &a[i2][j2]));
  }
  return 0;
}
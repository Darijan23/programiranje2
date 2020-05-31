#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef DEBUG
#define DEBUG(...)printf(__VA_ARGS__)
#endif

void bodovi(int iznos, int zadatak, int n, int *b, int *bio) {
	if (zadatak > n) {
		return;
	}
	*(bio + iznos) = 1;
	bodovi(iznos, zadatak + 1, n, b, bio);
	bodovi(iznos + *(b + zadatak), zadatak + 1, n, b, bio);
}

int main() {
  int n, *b, max = 0;
  int *bio; // polje u kojem se u indeksu i pamti da li je moguće postići broj od i bodova

  scanf("%d", &n);
  b = malloc(n * sizeof(int));
  for (int i = 0; i < n; ++i) {
    scanf("%d", b+i);
    max += b[i];
  }
  bio = malloc((max+1) * sizeof(int));
  memset(bio, 0, (max+1) * sizeof(int));
  bodovi(0, 0, n, b, bio);
  for (int i = 0; i <= max; i++) {
    if(bio[i]) printf("%d ", i);
  }
  free(b);
  free(bio);
  return 0;
}

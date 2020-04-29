#include <stdio.h>
#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

#define MAXR 10
#define MAXS 20
char *pronadji_adresu(char (*a)[MAXS], int S) {
  for (;; ++a) {
    for (int j = 0; j < S; ++j) {
      if (*(*a + j) == 'B') {
        return *a + j;
      }
    }
  }
}
void ispisi_indeks(char (*a)[MAXS], char *p) {
  int maxs = sizeof(*a) / sizeof(char);
  //printf("Adrese: %p %p %ld\n", *a, p, p - *a);
  printf("%ld %ld\n", (p - *a)/maxs, (p - *a)%maxs);
}

int main() {
  int R, S;
  char a[MAXR][MAXS];
  scanf("%d%d", &R, &S);

  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < S; ++j) {
      scanf(" %c", &a[i][j]);
    }
  }
  ispisi_indeks(a, pronadji_adresu(a, S));
  return 0;
}
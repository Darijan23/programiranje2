#include <stdio.h>
#include <stdlib.h>



#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

void swap(char ***a, char ***b) {
  char **tmp = *a;
  *a = *b;
  *b = tmp;
}

void prepisi(char **p1, char **p2, int r1, int r2, int n) {
  for (int s = 0; s < n/r1; ++s) {
    for (int r = 0; r < r1; ++r) {
      int i = s*r1+r;
      p2[i/(n/r2)][i%(n/r2)] = p1[r][s];
    }
  }
}

void ispisi(char **p, int r, int n) {
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < n/r; ++j) {
      printf("%c", p[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int n, q, *r;
  char **first, **second=NULL;
  scanf("%d%d", &n, &q);
  first = malloc(sizeof(char*));
  first[0] = malloc(n*sizeof(char));
  for (int i = 0; i < n; ++i) {
    scanf(" %c", first[0]+i);
  }
  r = malloc((q+1)*sizeof(int));
  r[0] = 1;
  for (int i = 1; i <= q; ++i) {
    scanf("%d", r+i);

    // ukoliko second nije NULL oslobodi memoriju na koju pokazuje second,
    // second je pokazivač na polje sa r[i-2] pokazivača na alocirane retke
    if (second)
    {
      for (int j = 0; j < r[i - 2]; j++) {
        free(second[j]);
      }
      free(second);
    }

    // alociraj memoriju za second sa r[i] redaka i n/r[i] stupaca
    second = malloc(r[i] * sizeof(char *));
    for (int j = 0; j < r[i]; j++) {
      second[j] = malloc((n/r[i]) * sizeof(char));
    }


    prepisi(first, second, r[i-1], r[i], n);
    swap(&first, &second);
  }
  ispisi(first, r[q], n);
  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

const char Z[] = "abcdefghijklmnopqrstuvwxyz#!?+-@/";
const int ZN = 33;

void ucrtaj(char **p, int ri, int si, int l, char c, int r) {
  // funkcija ucrtaj obavlja jedno ucrtavanje u polje p
  int ci = 0;

  while(Z[ci] != c) {
    ci++;
  }

  for (int i = ri; i < (ri + l < r ? ri + l : r); i++) {
     p[i][si] = Z[ci];
     ci = (ci + 1)%ZN;
  }

}

void ispisi(char **p, int r) {
  for (int i = 0; i < r; ++i) {
    printf("%s\n", p[i]);
  }
}

int main() {
  int r, s, k;
  char **p;
  // učitati inicijalne podatke
  scanf("%d %d %d ", &r, &s, &k);
  // alocirati polje
  p = malloc(r * sizeof(char*));
  for (int i = 0; i < r; i++) {
    p[i] = malloc((s + 1) * sizeof(char));
    memset(p[i], '.', (s + 1) * sizeof(char));
    p[i][s] = '\0';
  }
  // učitavati upite 
  // i pozivati funkciju ucrtaj
  for (int i = 1; i <= k; i++) {
    int ri, si, li;
    char ci;
    scanf("%d %d %d %c ", &ri, &si, &li, &ci);
    ucrtaj(p, ri, si, li, ci, r);
  }

  ispisi(p, r);
  // osloboditi memoriju
  for (int i = 0; i < r; i++) {
    free(p[i]);
  }
  free(p);

  return 0;
}

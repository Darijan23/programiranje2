#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif


// širina stupca
#define WIDTH 3
// jedinična visina stupca
#define HEIGHT 2
// razmak između stupaca
#define GAP 2

char **nacrtaj(int *p, int n, int h) {
  // alocirati memoriju za 2d polje koje treba vratiti
  char **out = malloc(h * HEIGHT * sizeof(char *));
  for (int i = 0; i < h * HEIGHT; i++) {
    out[i] = malloc(((n - 1) * (WIDTH + GAP)) * sizeof(char));
    memset(out[i], '.', (n * (WIDTH + GAP) - GAP) * sizeof(char));
  }
  // ucrtati ekvilajzer u polje
  for (int i = 0; i < n; i++) {
    for (int j = (h - p[i]) * HEIGHT; j < h * HEIGHT; j++) {
      for (int k = 0; k < WIDTH; k++) {
        *(*(out + j) + (i * (WIDTH + GAP)) + k) = '#';
      }
    }
  }

  return out;
}

void ispisi(char **ans, int n, int h) {
  for (int i = 0; i < h*HEIGHT; ++i) {
    for (int j = 0; j < n*(WIDTH+GAP)-GAP; ++j) {
      printf("%c", ans[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int n, *p, h = 0;
  scanf("%d", &n);
  p = malloc(n*sizeof(int));
  for (int i = 0; i < n; ++i) {
    scanf("%d", p+i);
    h = p[i]>h ? p[i] : h;
  }

  char **ans = nacrtaj(p, n, h);
  ispisi(ans, n, h);
  // osloboditi cjelokupnu alociranu memoriju
  for (int i = 0; i < h * HEIGHT; i++) {
    free(ans[i]);
  }
  free(ans);
  free(p);

  return 0;
}

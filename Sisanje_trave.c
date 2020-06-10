#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

#define MAXN 1000

int min(int a, int b) { return a < b ? a : b; }

int max(int a, int b) { return a > b ? a : b; }

int main() {
  int n, r[MAXN], s[MAXN], h[MAXN], w[MAXN];
  int mnr = 1e9, mxr = -1e9, H;
  int mns = 1e9, mxs = -1e9, W;
  // deklarirati varijablu za dinamički alocirano 2d polje
  int **a;

  scanf("%d", &n);
  for (int k = 0; k < n; ++k) {
    scanf("%d%d%d%d", &r[k], &s[k], &h[k], &w[k]);
    mnr = min(mnr, r[k]);
    mxr = max(mxr, r[k] + h[k]);
    mns = min(mns, s[k]);
    mxs = max(mxs, s[k] + w[k]);
  }
  H = mxr - mnr;
  W = mxs - mns;
  // alocirati polje dovoljnih dimenzija (H * W) i unositi tragove
  a = malloc(H * sizeof(int*));
  for (int i = 0; i < H; i++) {
    *(a + i) = malloc(W * sizeof(int));
    memset(*(a + i), 0, W * sizeof(int));
  }

  for (int k = 0; k < n; k++) {
    int i = *(r + k) - mnr;
    int j = *(s + k) - mns;

    for (int y = 0; y < *(h + k); y++) {
      for (int x = 0; x < *(w + k); x++) {
        (*(*(a + i + y) + j + x))++;
      }
    }
  }

  // ispisati polje
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      printf("%d ", *(*(a + i) + j));
    }
    printf("\n");
  }

  return 0;
}
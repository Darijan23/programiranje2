#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef DEBUG
#define DEBUG(...)printf(__VA_ARGS__)
#endif

int dr[8] = {2,  2, -2, -2,  1, -1,  1, -1};
int ds[8] = {1, -1,  1, -1,  2,  2, -2, -2};

void konj(int r, int s, int k, char **p, int n) {
  if (r < 0 || s < 0 || r > n - 1 || s > n - 1) {
    return;
  } else if (k == 0) {
    *(*(p + r) + s) = '#';
    return;
  }

  for (int i = 0; i < 8; i++) {
    konj(r + dr[i], s + ds[i], k - 1, p, n);
  }
}

int main() {
  int n, r, s, k;
  char **p;
  scanf("%d%d%d%d", &n, &r, &s, &k);
  p = malloc(n * sizeof(char*));
  for (int i = 0; i < n; ++i) {
    p[i] = malloc((n+1)* sizeof(char));
    memset(p[i], '.', (n+1)*sizeof(char));
    p[n] = '\0';
  }
  konj(r, s, k, p, n);
  for (int i = 0; i < n; ++i) {
    printf("%s\n", p[i]);
  }
  return 0;
}

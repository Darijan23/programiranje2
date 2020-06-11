#include <stdio.h>
#include <stdlib.h>



#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

void iznad(int **start, int **end, int k) {
    int n = *end - *start;
    int *s = NULL, *e = NULL;
    int *cs = NULL, *ce = NULL;

    for (int i = 0; i <= n; i++) {
        if (i < n && *(*start + i) > k) {
            if (cs == NULL) {
                cs = *start + i;
            }
            ce = *start + i;
        } else {
            if (s == NULL || (cs != NULL && ce-cs > e-s)) {
                s = cs;
                e = ce;
            }
            cs = NULL;
            ce = NULL;
        }
    }
    *start = s;
    *end = e;
}

int main() {
  int n, k, *a;
  scanf("%d%d", &n, &k);
  a = malloc(n * sizeof(int));
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  int *start = a, *end = a+n;
  iznad(&start, &end, k);
  printf("%d %d\n", (int)(start-a+1), (int)(end-a+1));
  return 0;
}

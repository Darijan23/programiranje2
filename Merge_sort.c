#include <stdio.h>
#include <stdlib.h>



#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

void ispisi(int *a, int n) {
  for (int i = 0; i < n; ++i) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

void merge(int *a, int n1, int *b, int n2, int *merged) {
    int *ap = a, *bp = b;

    for (int i = 0; i < n1 + n2; i++) {
        if (ap - a < n1 && (bp - b >= n2 || *ap <= *bp)) {
            *merged = *ap;
            ap++;
        } else {
            *merged = *bp;
            bp++;
        }
        merged++;
    }    
}


int main() {
  int n1, n2, *a, *b, *merged;
  scanf("%d%d", &n1, &n2);
  a = malloc(n1 * sizeof(int));
  b = malloc(n2 * sizeof(int));
  merged = malloc((n1 + n2) * sizeof(int));
  for (int i = 0; i < n1; ++i) {
    scanf("%d", a+i);
  }
  for (int i = 0; i < n2; ++i) {
    scanf("%d", b+i);
  }
  merge(a, n1, b, n2, merged);
  ispisi(merged, n1+n2);
  free(a);
  free(b);
  free(merged);
  return 0;
}
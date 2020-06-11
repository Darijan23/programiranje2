#include <stdio.h>
#include <stdlib.h>



#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

void reduciraj(int **lo, int **hi, int k) {
    int *mid = *lo + ((*hi - *lo) / 2);
    if (*mid > k) {
        *hi = mid;
    } else {
        *lo = mid;
    }    
}

int main() {
  int n, q, *a;
  scanf("%d%d", &n, &q);
  a = malloc(n * sizeof(int));
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  for (int i = 0; i < q; ++i) {
    int k, *lo = a, *hi = a+n;
    scanf("%d", &k);
    while(lo+1<hi) {
      reduciraj(&lo, &hi, k);
    }
    if (*lo==k) {
      printf("%d\n", (int)(lo-a));
    } else {
      printf("-\n");
    }
  }
  free(a);
  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef DEBUG
#define DEBUG(...)printf(__VA_ARGS__)
#endif

int moze(int *a, int n, int k, int p) {
    if (p == 0) {
        return k == 0;
    }

    for (int i = 0; i < n; i++) {
        if (moze(a, n, k - *(a + i), p - 1)) {
            return 1;
        }
    }    

    return 0;    
}

int main() {
  int n, q, *a;
  scanf("%d%d", &n, &q);
  a = malloc(n * sizeof(int));
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  for (int i = 0; i < q; ++i) {
    int k, p;
    scanf("%d%d", &k, &p);
    if (moze(a, n, k, p)) {
      printf("DA\n");
    } else {
      printf("NE\n");
    }
  }
  return 0;
}
#include <stdio.h>
#include <stdlib.h>



#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

void max_charger(int **start_charge, int **finish_charge) {
    int n = *finish_charge - *start_charge;
    int *a = *start_charge;

    *finish_charge = *start_charge;

    int *start = *start_charge;
    int *finish = *finish_charge;

    for (int i = 0; i < n; i++) {
        if (*(a + i) > *(a + i - 1)) {
            finish = a + i;
        } else {
            start = a + i;
        }
        
        if (finish - start > *finish_charge - *start_charge) {
            *start_charge = start;
            *finish_charge = finish;
        }        
    }    
}

int main() {
  int n, *a;
  scanf("%d", &n);
  a = malloc(n * sizeof(int));
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  int *start_charge = a, *finish_charge = a+n;
  max_charger(&start_charge, &finish_charge);
  printf("%d\n", (int)(finish_charge-start_charge));
  for (int *t = start_charge; t != finish_charge+1; ++t) {
    printf("%d ", (int)(t-a));
  }
  printf("\n");
  free(a);
  return 0;
}

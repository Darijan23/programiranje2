#include <stdio.h>
#include <stdlib.h>



#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif


void duplicate_big(int **a, int *n, int k) {
  // odrediti veličinu rezultantnog polja
  int c = *n;
  for (int i = 0; i < *n; i++) {
      if (*(*a + i) > k) {
          c++;
      }    
  } 
  
  // realocirati memorijski prostor dovoljan za dopisivanje svih potrebnih elemenata
  *a = realloc(*a, c * sizeof(int));

  // dopisati elemente
  int j = *n;
  for (int i = 0; i < *n; i++) {
      if (*(*a + i) > k) {
          *(*a + j) = *(*a + i);
          j++;
      }            
  }  

  // promijeniti vrijednost duljine niza
  *n = c;
}

void print(int *a, int n) {
  for (int i = 0; i < n; ++i) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

int main() {
  int n, k, *a;
  // učitati n
  scanf("%d ", &n);

  // alocirati prostor za upis elemenata niza
  a = malloc(n * sizeof(int));

  // učitati elemente niza
  for (int i = 0; i < n; i++) {
      scanf("%d ", a + i);
  }  

  // učitati k
  scanf("%d ", &k);

  duplicate_big(&a, &n, k);
  print(a, n);
  return 0;
}

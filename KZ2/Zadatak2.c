#include <stdio.h>
#include <stdlib.h>



#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif


void compress_instructions(char *a, int n, char **u, int *nu) {
  // odrediti veličinu komprimiranog niza nu
  *nu = 1;
  char c = *a;

  if (n == 1) {
      *u = malloc(sizeof(char));
      **u = *a;
      return;
  }
  
  
  for (int i = 0; i < n; i++) {
      if (*(a + i) != c) {
          c = *(a + i);
          (*nu)++;
      }
  }

  *nu *= 2;

  // alocirati memorijski prostor dovoljan za komprimirane instrukcije
  *u = malloc(*nu * sizeof(char));

  // upisati komprimirane instrukcije u u
  int j = 0, k = 0;
  c = *a;  

  for (int i = 0; i < n; i++) {
      while (*(a + i) == c && i < n + 1) {
          i++;
          k++;
      }
      *(*u + j) = k + '0';
      *(*u + j + 1) = c;
      c = *(a + i);
      k = 1;
      j += 2;
  }
}

void print(char *a, int n) {
  for (int i = 0; i < n; ++i) {
    printf("%c", a[i]);
  }
  printf("\n");
}

int main() {
  int n, nu;
  char *a, *u;
  // učitati duljinu niza n
  scanf("%d ", &n);

  // alocirati prostor za unos instrukcija
  a = malloc((n + 1) * sizeof(char));

  // učitati niz instrukcija
  scanf("%s ", a);

  compress_instructions(a, n, &u, &nu);
  print(u, nu);

  // osloboditi cjelokupnu alociranu memoriju
  free(a);
  free(u);

  return 0;
}

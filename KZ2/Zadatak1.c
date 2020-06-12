#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

#define MAXN 1000


// Rekurzivna funkcija broji koliko ima jednoznamenkastih brojeva u polju
int pretraga(int *a, int n) {
    if (n == 0) {
        return 0;
    }

    return !(*a / 10) + pretraga(a + 1, n - 1);
}


int main() {
  int n;
  int a[MAXN];

  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  printf("%d", pretraga(a, n));	// Dopisati parametre funkcije
  
  return 0;
}
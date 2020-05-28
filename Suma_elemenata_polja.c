#include <stdio.h>
#include <stdlib.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

#define MAX_SIZE 10

int suma_rekurzivno(int *array, int n) {
	if (n == 0) {
		return *array;
	}
	return *(array + n) + suma_rekurzivno(array, --n);
}

int main() {
  int array[MAX_SIZE];
  int i = 0;

  for (i=0; i<MAX_SIZE; i++) {
    scanf("%d", array+i);
  }
  printf("%d", suma_rekurzivno(array, MAX_SIZE - 1));
  return 0;
}
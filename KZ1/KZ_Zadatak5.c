#include <stdio.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

#define SIZE 512

// Implementirati funkciju za bubble sort
void bubble_sort(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < n; j++) {
      if (arr[j] > arr[j - 1]) {
        int tmp = arr[j];
        arr[j] = arr[j - 1];
        arr[j - 1] = tmp;
      }
    }
  }
}

int main() {
  int n, array[SIZE];

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &array[i]);
  }

  // Dodati poziv funkcije za sortiranje
  bubble_sort(array, n);

  for (int i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }

  return 0;
}

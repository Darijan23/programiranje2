#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

void swap(char *a, char *b) {
  char t = *a;
  *a = *b;
  *b = t;
}

void sort(char *arr, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = i; j < size; j++) {
      if (arr[i] > arr[j]) {
        swap(arr+j, arr+i);
      }
    }
  }
}

void print_permutations(char *ans, char *chr, int *bio, int cur, int n) {
  if (cur == n) {
    printf("%s\n", ans);
  }
  
  for (int i = 0; i < n; i++) {
    if (*(bio + i) || (i > 0 && !(*(bio + i - 1)) && *(chr + i) == *(chr + i - 1))) {
      continue;
    }

    *(ans + cur) = *(chr + i);
    *(bio + i) = 1;
    print_permutations(ans, chr, bio, cur + 1, n);
    *(bio + i) = 0;        
  }
}

int main() {
  int n;
  char *ans, *chr;
  int *bio;
  scanf("%d",&n);
  chr = malloc((n+1) * sizeof(char));
  bio = malloc(n * sizeof(int));
  memset(bio, 0, n * sizeof(int));
  scanf(" %s", chr);
  sort(chr, n);
  ans = malloc((n+1) * sizeof(char));
  ans[n] = 0;
  print_permutations(ans, chr, bio, 0, n);
  free(ans);
  free(chr);
  free(bio);
  return 0;
}

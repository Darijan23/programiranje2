#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

void odvezi(char *z, char **cur, int size, char d, int k) {
  if (d == 'G') {
    *cur += k;
  } else {
    *cur -= k;
  }

  if (* cur - z < 0) {
    *cur = z;
  } else if (*cur - z >= size) {
    *cur = z + size - 1;
  }

}

int main() {
  int n, q;
  char *z, *cur;
  scanf("%d%d", &n, &q);
  z = malloc((n+1) * sizeof(char));
  scanf(" %s", z);

  cur = z;
  for (int i = 0; i < q; ++i) {
    char d;
    int k;
    scanf(" %c%d", &d, &k);
    odvezi(z, &cur, n, d, k);
    printf("%c\n", *cur);
  }
  return 0;
}
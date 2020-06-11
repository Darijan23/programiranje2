#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

int binarni_u_dekadski(char *s, int i) {
  if (!i) {
    return s[i] - '0';
  }

  return s[i] - '0' + binarni_u_dekadski(s, --i) * 2;
}

int main() {
  int n;
  scanf("%d", &n);
  char *s;
  s = malloc(31 * sizeof(char));
  for (int i = 0; i < n; ++i) {
    scanf(" %s", s);
    printf("%d\n", binarni_u_dekadski(s, strlen(s) - 1));
  }
  free(s);
  return 0;
}
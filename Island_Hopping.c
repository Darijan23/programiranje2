#include <stdio.h>
#include <string.h>
#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

#define MAXN 10000

int search(int u, int v, int *m, int *bio) {
  if (u == v) {
    return 1;
  } else if (*(bio + u)) {
    return 0;
  }

  *(bio + u) = 1;

  return search(*(m + u), v, m, bio);
}

int main() {
  int n, q;
  int m[MAXN];  //mostovi
  int bio[MAXN];  // polje u koje se sprema da li je pojedini otok posjecen
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &m[i]);
  }
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int u, v;
    memset(bio, 0, sizeof(bio));
    scanf("%d%d", &u, &v);
    if (search(u, v, m, bio)) {
      printf("DA\n");
    } else {
      printf("NE\n");
    }
  }
  return 0;
}

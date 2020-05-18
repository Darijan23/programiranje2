#include <stdio.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif
#define MAXR 10
#define MAXS 20

char *pronadji(char (*)[MAXS], char, int);
void ispisi_podmatricu(char (*)[MAXS], char *, char *);

int main() {
  char a[MAXR][MAXS];
  int R, S;
  scanf("%d%d%*[\r\n]s", &R, &S);
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < S; ++j) {
      scanf("%c ", &a[i][j]);
    }
  }
  ispisi_podmatricu(a, pronadji(a, 'A', S), pronadji(a, 'B', S));
  return 0;
}

char *pronadji(char (*m)[MAXS], char c, int n) {
  while(1) {
    for (int i = 0; i < n; i++) {
      if (*(*m + i) == c) {
        return *m + i;
      }
    }
    m++;
  }
}

void ispisi_podmatricu(char (*m)[MAXS], char *a, char *b) {
  int s = sizeof(m[0]) / sizeof(char);
  int imax, imin, jmax, jmin;

  if ((a - *m) / s >  (b - *m) / s) {
    imax = (a - *m) / s;
    imin = (b - *m) / s;
  } else {
    imax = (b - *m) / s;
    imin = (a - *m) / s;
  }

  if ((a - *m) % s >  (b - *m) % s) {
    jmax = (a - *m) % s;
    jmin = (b - *m) % s;
  } else {
    jmax = (b - *m) % s;
    jmin = (a - *m) % s;
  }

  for (int i = imin; i <= imax; i++) {
    for (int j = jmin; j <= jmax; j++) {
      printf("%c", *(*(m + i) + j));
    }
    printf("\n");
  }
}

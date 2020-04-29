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

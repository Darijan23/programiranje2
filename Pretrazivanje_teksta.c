#include <stdio.h>
#include <string.h>
#include <ctype.h>


#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

int main() {
  char s[31], lp[301];
  int n=0, l=0;

  FILE *fp = fopen("input.dat", "r");

  scanf("%[^\n]s", s);
  n = strlen(s);

  while (fgets(lp, sizeof lp, fp)) {
    int col=0, k=0, ans[300]={};
    l++;

    while (*(lp+col)) {
      int i = 0;

      while (*(s+i) && tolower(*(lp+col+i))==tolower(*(s+i))) {
          i++;
      }

      if (i==n) {
          ans[k++] = col+1;
      }

      col++;
    }

    if (ans[0]) {
      int i = 0;
      printf("line: %d column:", l);
      while (ans[i]) {
          printf(" %d", ans[i++]);
      }
      printf("\n");
    }
  }

  fclose(fp);
  
  return 0;
}
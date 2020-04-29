#include <stdio.h>

#ifndef DEBUG
#define DEBUG(...)printf(_VA_ARGS_)
#endif

#define MAXA 200

int main() {
  int n;
  int br; // broj mladih
  int mn; // godine starosti najmladje osobe
  int *pbr=NULL, *pmn=NULL;
  pbr = &br;
  pmn = &mn;
  *pbr = 0;
  *pmn = MAXA;

  scanf("%d ", &n);

  for (int i = 0; i < n; ++i) {
  	int in;
  	scanf("%d ", &in);
  	if (in >= 10 && in <= 30) {
  		(*pbr)++;
  	}

  	if (in < *pmn) {
  		*pmn = in;
  	}
  }

  printf("%d\n%d", *pbr, *pmn);

  return 0;
}
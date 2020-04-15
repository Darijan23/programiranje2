#include <stdio.h>
#include <string.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

#define N 100

typedef struct {
  char name[32];
  int numFound;
} names;

int main() {
  int n;
  names friends[N];

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%s", friends[i].name);
    friends[i].numFound = 0;
  }

  // Deklaracija i otvaranje datoteke
  FILE *fp;
  fp = fopen("input.dat", "r");

  // Procitati sadrzaj datoteke i prebrojati koliko se puta koje ime spominje
  while (!feof(fp)) {
    char tmp[32];
    fscanf(fp, "%s", tmp);
    for (int i = 0; i < n; i++) {
      if (!strcmp(tmp, friends[i].name)) {
        friends[i].numFound++;
      }
    }
  }

  // Provjeriti ako je spomenut samo jedan prijatelj samo jednom te ispisati rjesenje
  int c = 0;
  for (int i = 0; i < n; i++) {
    c += friends[i].numFound;
  }

  if (c == 1) {
    printf("DA");
  } else {
    printf("NE");
  }

  // Zatvoriti datoteku
  fclose(fp);

  return 0;
}
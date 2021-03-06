#include <stdio.h>
#include <string.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

typedef struct {
  char from;
  char to;
} substitution;

// Funkcija koja mijenja znakove odgovarajucom zamjenom
void substitute_character(char password[], substitution s) {
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] == s.from) {
      password[i] = s.to;
    }
  }
}

int main() {
  char password[128];
  int n;
  substitution s[16];

  scanf("%s", password);

  // Deklaracija i otvaranje datoteke
  FILE *fp;
  fp = fopen("input.dat", "r");

  // Ucitati broj zamjena i sve zamjene iz datoteke u polje struktura
  fscanf(fp, "%d ", &n);
  for (int i = 0; i < n; i++)
  {
    fscanf(fp, "%c %c ", &s[i].from, &s[i].to);
  }

  for (int i = 0; i < n; i++) {
    substitute_character(password, s[i]);
  }

  printf("%s", password);

  // Zatvoriti datoteku
  fclose(fp);

  return 0;
}

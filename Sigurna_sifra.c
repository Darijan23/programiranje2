#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

// Napisati funkciju koja provjerava ako postoje duplikati
// Vraca 1 ako postoje i 0 ako ne postoje
int check_duplicates(char pass[][32], int n) {
  int c = 0;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (!strcmp(pass[i], pass[j])) {
        c++;
      }
    }
  }
  return c;
}

// Napisati funkciju koja provjerava ispravnost sifre
// Vraca 1 ako je sifra ispravna i 0 ako nije
int check_password(char password[]) {
  int u = 0, l = 0, n = 0, p = 0;
  if (strlen(password) < 8) {
    return 0;
  } else {
    for (int i = 0; i < strlen(password); ++i) {
      if (isupper(password[i])) {
        u++;
      } else if(islower(password[i])) {
        l++;
      } else if (isalnum(password[i]) && !isalpha(password[i])) {
        n++;
      } else if (ispunct(password[i])) {
        p++;
      }
    }
  }  
  return u && l && n && p;
}

int main() {
  int n;
  char passwords[128][32];

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%s", passwords[i]);
  }

  if (check_duplicates(passwords, n)) {
    printf("DUPLIKATI");
  } else {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      cnt += check_password(passwords[i]);
    }
    printf("%d", cnt);
  }

  return 0;
}
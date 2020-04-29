#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
  char ime[26];
  char prezime[26];
  int god;
} gradanin;

void modify(gradanin *g);
void sort(gradanin g[], int);
int compare(gradanin g1, gradanin g2);

int main() {
  int n;
  gradanin g[100];

  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%s %s %d", g[i].ime, g[i].prezime, &g[i].god);
    modify(g+i);
  }

  sort(g, n);

  for (int i = 0; i < n; ++i) {
    printf("%2d; %s, %s \n", g[i].god, g[i].prezime, g[i].ime );
  }

  return 0;
}

void modify(gradanin *g) {
  int n = strlen(g->ime);
  g->god = 2017-(g->god);
  g->ime[0] = toupper(g->ime[0]);
  g->prezime[0] = toupper(g->prezime[0]);

  for (int i = 1; i < n; i++) {
    g->ime[i] = tolower(g->ime[i]);
  }

  n = strlen(g->prezime);
  for (int i = 1; i < n; i++) {
    g->prezime[i] = tolower(g->prezime[i]);
  }
}

void sort(gradanin g[], int n) {
  for (int i = 1; i < n; ++i) {
    gradanin tmp = g[i];
    int j = i;

    while (j > 0 && compare(g[j - 1], tmp) > 0) {
      g[j] = g[j - 1];
      j--;
    }
    g[j] = tmp;
  }
}

int compare(gradanin g1, gradanin g2) {
  if (g1.god == g2.god) {
    if (!strcmp(g1.prezime, g2.prezime)) {
      return strcmp(g1.ime, g2.ime);
    } else {
      return strcmp(g1.prezime, g2.prezime);
    }
  }
  return g1.god > g2.god;
}
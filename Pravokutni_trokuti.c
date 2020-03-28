#include <stdio.h>
#include <math.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

typedef struct {
  int a;
  int b;
  int c;
} triangle;

// Napisati funkciju za ucitavanje duljina starnica
void load_lengths(triangle t[], int n) {
  for (int i = 0; i < n; ++i) {
    scanf("%d %d %d ", &t[i].a, &t[i].b, &t[i].c);
  }
}

// Napisati funkciju koja vraca 1 ako se radi te 0 ako se ne radi o pravokutnom trokutu
int check_right_angle(triangle t) {
  int uvjet = 0;
  if (t.a > t.b && t.a > t.c) {
    uvjet = pow(t.a, 2) == pow(t.b, 2) + pow(t.c, 2);
  } else if (t.b > t.a && t.b > t.c) {
    uvjet = pow(t.b, 2) == pow(t.a, 2) + pow(t.c, 2);
  } else {
    uvjet = pow(t.c, 2) == pow(t.a, 2) + pow(t.b, 2);
  }
  return uvjet;
}

int main() {
  int n;
  triangle t[128];

  scanf("%d", &n);

  // Napisati poziv funkcije za ucitavanje duljina
  load_lengths(t, n);

  for (int i = 0; i < n; i++) {
    if (check_right_angle(t[i])) {
      printf("DA\n");
    } else {
      printf("NE\n");
    }
  }

  return 0;
}

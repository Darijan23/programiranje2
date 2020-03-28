#include <stdio.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

typedef struct {
  int x;
  int y;
} point;

typedef struct {
  float k;
  float l;
} line;

// Napisati funkciju za ucitavanje tocaka
void load_points(point p[], int n) {
  for (int i = 0; i < n; ++i) {
    scanf("%d %d ", &p[i].x, &p[i].y);
  }
}

line calculate_coefficients(point p1, point p2) {
  line l;

  l.k = (float) (p2.y - p1. y) / (p2.x - p1.x);
  l.l = p1.y - l.k * p1.x;

  return l;
}

int check_collinearity(point p[], int n) {
  line l;

  l = calculate_coefficients(p[0], p[1]);

  // Napisati dio koda za provjeru kolinearnosti
  int uvjet = 1;
  for (int i = 2; i < n; ++i) {
    line c = calculate_coefficients(p[0], p[i]);
    if (c.k != l.k || c.l != l.l) {
      uvjet = 0;
      break;
    }
  }
  return uvjet;
}

int main() {
  int n;
  point p[128];

  scanf("%d", &n);

  // Napisati poziv funkcije za ucitavanje tocaka
  load_points(p, n);

  if (check_collinearity(p, n)) {
    printf("DA");
  } else {
    printf("NE");
  }

  return 0;
}

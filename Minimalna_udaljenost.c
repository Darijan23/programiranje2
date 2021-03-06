#include <stdio.h>
#include <math.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

typedef struct {
  float x;
  float y;
  float z;
} point;

// Napisati funkciju za ucitavanje tocaka
void load_points(point p[], int n) {
  for (int i = 0; i < n; ++i) {
    scanf("%f %f %f ", &p[i].x, &p[i].y, &p[i].z);
  }
}

float distance(point p1, point p2) {
  return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2));
}

float get_minimal_distance(point p[], int n) {
  float min = 1000000;

  // Napisati dio koda za pronalazak najmanje udaljenosti izmedu tocaka

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      float dist = distance(p[i], p[j]);
      if (dist < min && dist > 0) {
        min = dist;
      }
    }
  }

  return min;
}

int main() {
  int n;
  point p[128];

  scanf("%d", &n);

  // Napisati poziv funkcije za ucitavanje tocaka
  load_points(p, n);

  printf("%.2f", get_minimal_distance(p, n));

  return 0;
}

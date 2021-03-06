#include <stdio.h>
#include <stdlib.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

typedef struct {
  int x;
  int y;
} point;

typedef struct {
  char name;
  int distance;
  point p;
} contestant;

point find_destination(char mat[][128], int m, int n) {
  point p;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (mat[i][j] == '#') {
        p.x = i;
        p.y = j;

        return p;
      }
    }
  }
  
  return p;
}

int find_contestants(contestant c[], char mat[][128], int m, int n) {
  int size = 0;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (mat[i][j] != '.' && mat[i][j] != '#') {
        c[size].name = mat[i][j];
        c[size].p.x = i;
        c[size].p.y = j;
        c[size].distance = 0;

        size++;
      }
    }
  }

  return size;
}

void calculate_distances(contestant c[], int size, point dest) {
  for (int i = 0; i < size; i++) {
    c[i].distance = abs(c[i].p.x - dest.x) + abs(c[i].p.y - dest.y);
  }
}

// Napisati funkciju za usporedbu
// Funkcija vraca 1 ako je potrebno zamijeniti elemente i 0 ako nije
int compare(contestant c1, contestant c2) {
  if (c1.distance == c2.distance) {
    return c1.name > c2.name;
  }
  return c1.distance > c2.distance;
}

void sort(contestant c[], int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 1; j < size; j++) {
      if (compare(c[j - 1], c[j])) {
        contestant tmp = c[j - 1];
        c[j - 1] = c[j];
        c[j] = tmp;
      }
    }
  }
}

int main() {
  int m, n;
  char mat[128][128];

  scanf("%d %d", &m, &n);

  // Deklaracija i otvaranje datoteke
  FILE *fp;
  fp = fopen("input.dat", "r");

  // Procitati sadrzaj datoteke i upisati ga u matricu mat
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      fscanf(fp, " %c", &mat[i][j]);
    }
  }

  point dest = find_destination(mat, m, n);

  contestant c[16];
  int size = find_contestants(c, mat, m, n);
  calculate_distances(c, size, dest);


  sort(c, size);

  for (int i = 0; i < size; i++) {
    printf("%c %d\n", c[i].name, c[i].distance);
  }

  // Zatvoriti datoteku
  fclose(fp);

  return 0;
}

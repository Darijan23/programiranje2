#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef DEBUG
#define DEBUG(...)printf(__VA_ARGS__)
#endif

char abc[26][3][2] = {
  {{'O', '.'}, {'.', '.'}, {'.', '.'}}, // A
  {{'O', '.'}, {'O', '.'}, {'.', '.'}}, // B
  {{'O', 'O'}, {'.', '.'}, {'.', '.'}}, // C
  {{'O', 'O'}, {'.', 'O'}, {'.', '.'}}, // D
  {{'O', '.'}, {'.', 'O'}, {'.', '.'}}, // E
  {{'O', 'O'}, {'O', '.'}, {'.', '.'}}, // F
  {{'O', 'O'}, {'O', 'O'}, {'.', '.'}}, // G
  {{'O', '.'}, {'O', 'O'}, {'.', '.'}}, // H
  {{'.', 'O'}, {'O', '.'}, {'.', '.'}}, // I
  {{'.', 'O'}, {'O', 'O'}, {'.', '.'}}, // J
  {{'O', '.'}, {'.', '.'}, {'O', '.'}}, // K
  {{'O', '.'}, {'O', '.'}, {'O', '.'}}, // L
  {{'O', 'O'}, {'.', '.'}, {'O', '.'}}, // M
  {{'O', 'O'}, {'.', 'O'}, {'O', '.'}}, // N
  {{'O', '.'}, {'.', 'O'}, {'O', '.'}}, // O
  {{'O', 'O'}, {'O', '.'}, {'O', '.'}}, // P
  {{'O', 'O'}, {'O', 'O'}, {'O', '.'}}, // Q
  {{'O', '.'}, {'O', 'O'}, {'O', '.'}}, // R
  {{'.', 'O'}, {'O', '.'}, {'O', '.'}}, // S
  {{'.', 'O'}, {'O', 'O'}, {'O', '.'}}, // T
  {{'O', '.'}, {'.', '.'}, {'O', 'O'}}, // U
  {{'O', '.'}, {'O', '.'}, {'O', 'O'}}, // V
  {{'.', 'O'}, {'O', 'O'}, {'.', 'O'}}, // W
  {{'O', 'O'}, {'.', '.'}, {'O', 'O'}}, // X
  {{'O', 'O'}, {'.', 'O'}, {'O', 'O'}}, // Y
  {{'O', '.'}, {'.', 'O'}, {'O', 'O'}}, // Z
};

void upisi(char z, char **m, int red, int stup) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      m[red + i][stup + j] = abc[z - 'A'][i][j];
    }
  }
}

int main() {
  int l;
  scanf("%d ", &l);
  char *s = malloc((l + 1) * sizeof(char));
  int spaces = 0, prevspaces = 0, maxlen = 0;

  for (int i = 0; i < l; i++) {
    scanf("%c", s + i);
  }

  s[l] = '\0';
  prevspaces = -1;

  for (int i = 0; i <= l; i++)
  {
    if (s[i] == ' ' || s[i] == '\0') {
      if (i - prevspaces - 1 > maxlen) {
        maxlen = i - prevspaces - 1;
      }
      spaces++;
      prevspaces = i;
    }
  }

  char **mat = malloc(spaces * 3 * sizeof(char*));

  for (int i = 0; i < spaces * 3; i++) {
    *(mat + i) = malloc(maxlen * 2 * sizeof(char));
    memset(mat[i], '.', maxlen * 2 * sizeof(char));
  }

  int red = 0;
  prevspaces = 0;

  for (int i = 0; i <= l; i++) {
    if (*(s + i) == ' ' || *(s + i) == '\0') {
      for (int j = prevspaces; j < i; j++) {
        upisi(s[j], mat, red, (j - prevspaces) * 2);
      }
      red += 3;
      prevspaces = i + 1;
    }
  }

  for (int i = 0; i < spaces * 3 ; i++) {
    for (int j = 0; j < maxlen * 2; j++) {
      printf("%c", mat[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < spaces * 3; i++) {
    free(mat[i]);
  }
  free(mat);
  free(s);

  return 0;
}

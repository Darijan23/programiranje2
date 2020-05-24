#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif


typedef struct Node {
  char letter;
  struct Node *next;
} node;

void insert(node **head, int p, char c) {
  node *trenutni, *novi = malloc(sizeof(node));
  trenutni = *head;
  novi->letter = c;

  if (p) {
    while(p > 1) {
      trenutni = trenutni->next;
      p--;
    }
    novi->next = trenutni->next;
    trenutni->next = novi;
  } else {
    novi->next = *head;
    *head = novi;
  }
}

int main() {
  int n;
  char line[33]; // jedan znak vise za '\0'
  node *head = NULL;

  scanf("%[^\n]", line);

  for (int p = 0; p < strlen(line); p++) {
    insert(&head, p, line[p]);
  }

  scanf("%d", &n);

  for (int i = 0; i<n; i++) {
    int p;
    char c;
    scanf("%d %c", &p, &c);
    insert(&head, p-1, c);
  }

  for (node *cur = head; cur != NULL; cur = cur->next) {
    printf("%c", cur->letter);
  }
  printf("\n");
  return 0;
}

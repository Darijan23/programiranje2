#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif


typedef struct Node {
  char val;
  struct Node *next;
} node;

void append(node **head, node **tail, char val) {
  node *el = malloc(sizeof(node));
  el->val = val;
  el->next = NULL;
  if (*head == NULL) {
    *head = el;
  } else {
    (*tail)->next = el;
  }
  *tail = el;
}

void print_list(node *p) {
  while(p != NULL) {
    printf("%c", p->val);
    p = p->next;
  }
  printf("\n");
}

node **podijeli(node *head, int k, int *a) {
    node **out = malloc(k * sizeof(node *));
    node *trenutni = NULL, *start = NULL;

    start = head;
    trenutni = head;

    for (int i = 0; i < k; i++) {
        *(out + i) = start;
        trenutni = start;
        for (int j = 0; j < *(a + i) - 1; j++) {
            trenutni = trenutni->next;
        }
        start = trenutni->next;
        trenutni->next = NULL;
    }

    return out;
}

int main() {
  int n, k, *a;
  char *values;
  node *head = NULL, *tail = NULL;

  scanf("%d%d", &n, &k);
  values = malloc((n+1)*sizeof(char));  // jedan znak vise za '\0'
  scanf(" %[^\n]", values);

  a = malloc(k * sizeof(int));
  for (int i = 0; i < k; ++i) {
    scanf("%d", a+i);
  }

  for (int i = 0; i < n; ++i) {
    append(&head, &tail, values[i]);
  }

  node **liste = podijeli(head, k, a);

  for (int i = 0; i < k; i++) {
    print_list(liste[i]);
  }
  return 0;
}
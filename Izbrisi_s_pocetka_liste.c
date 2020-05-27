#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

typedef struct node {
  char val;
  struct node *next;
} Node;

void izbrisi_pocetak(Node **head, int k) {
  Node *trenutni = NULL, *prethodni = NULL; 
  int i = 0;
  trenutni = *head;
  while(trenutni != NULL && i < k) {
    prethodni = trenutni;
    trenutni = trenutni->next;
    i++;
    free(prethodni);
  }
  *head = trenutni;
}

void upisi_kraj(Node **head, char *p, int n) {
  Node **trenutni = head;
  while (*trenutni!=NULL) trenutni = &((*trenutni)->next);
  for (int i = 0; i < n; ++i) {
    Node *novi = malloc(sizeof(Node));
    novi->val = p[i];
    novi->next = NULL;
    *trenutni = novi;
    trenutni = &(novi->next);
  }
}

void ispisi(Node *head) {
  Node *trenutni = head;
  while (trenutni != NULL) {
    printf("%c", trenutni->val);
    trenutni = trenutni->next;
  }
  printf("\n");
}

int main() {
  int n;
  Node *head=NULL;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    char c;
    scanf(" %c", &c);
    if (c=='d') {
      int m;
      scanf("%d", &m);
      char *s = malloc((m+1)*sizeof(char));
      scanf("%s", s);
      upisi_kraj(&head, s, m);
      free(s);
    } else {
      int k;
      scanf("%d", &k);
      izbrisi_pocetak(&head, k);
    }
    ispisi(head);
  }
  return 0;
}
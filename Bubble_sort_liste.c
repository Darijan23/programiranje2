#include <stdio.h>
#include <stdlib.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif


typedef struct Node{
  struct Node *next;
  int val;
} node;

int add_node(node **head, int val) {
  node *new;

  new = (node *)malloc(sizeof(node));
  if (!new) return -1;

  new->val = val;
  new->next = *head;
  *head = new;

  return 0;
}

void print_list(node *head) {
  node *trenutni;

  if(!head) return;

  for(trenutni=head; trenutni!=NULL; trenutni=trenutni->next) printf("%d  ", trenutni->val);
  printf("\n");
}

void bubble_sort(node **head) {
  node *temp1 = NULL, *temp2 = NULL, *temp3 = NULL;
  int zamjene;

  if (!*head || !(*head)->next){
    return;
  }

  do {
    zamjene = 0;
    temp1 = *head;
    temp2 = (*head)->next;
    if (temp1->val > temp2->val) {
      temp1->next = temp2->next;
      temp2->next = temp1;
      *head = temp2;
      zamjene++;
    }

    for (temp1 = *head; temp1->next->next != NULL; temp1 = temp1->next) {
      temp2 = temp1->next;
      temp3 = temp2->next;

      if (temp2->val > temp3->val) {
        temp1->next = temp3;
        temp2->next = temp3->next;
        temp3->next = temp2;
        zamjene++;
      }
    }
    print_list(*head);
  } while (zamjene>0);
}

int main() {
  int n;
  node *head = NULL;

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int val;
    scanf("%d", &val);
    add_node(&head, val);
  }

  printf("Lista prije sortiranja:\n");
  print_list(head);

  printf("\nLista za vrijeme sortiranja:\n");
  bubble_sort(&head);

  printf("\nSortirana lista:\n");
  print_list(head);

  return 0;
}

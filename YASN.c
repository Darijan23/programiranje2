#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

typedef struct Node {
  int friend;
  struct Node *next;
} node;

void insfr(node **g, int t) {
    node *new = malloc(sizeof(node));
    new->friend = t;
    new->next = *g;
    *g = new;
}

void friends(node **g, int t1, int t2) {
    for (node *trenutni = *(g + t1); trenutni != NULL; trenutni = trenutni->next) {
        if (trenutni->friend == t2) {
            printf("DA\n");
            return;
        }        
    }
    printf("NE\n");
    return;    
}

int main() {
    int n, m, q;

    scanf("%d %d ", &n, &m);

    node **g ;
    g = malloc((n + 1) * sizeof(node *));

    for (int i = 0; i < n + 1; i++) {
        *(g + i) = NULL;
    }
    
    for (int i = 0; i < m; i++) {
        int t1, t2;
        scanf("%d %d ", &t1, &t2);
        insfr(g + t1, t2);
        insfr(g + t2, t1);
    }

    scanf("%d ", &q);

    for (int i = 0; i < q; i++) {
        int t1, t2;
        scanf("%d %d ", &t1, &t2);
        friends(g, t1, t2);
    }
    
    
    return 0;
}

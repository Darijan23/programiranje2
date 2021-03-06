#include <stdio.h>
#include <stdlib.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

typedef struct Node {
    struct Node *next;
    int val;
} node;

int add(node **head, int val) {
    node *new;
    new = (node *) malloc(sizeof(node));
    if (!new) return -1;

    new->val = val;
    new->next = *head;
    *head = new;
    return 0;
}

int print(node *head) {
    node *trenutni;

    if (!head) return -1;

    printf("Lista: ");
    for (trenutni=head; trenutni!=NULL; trenutni=trenutni->next) {
        printf("%d ", trenutni->val);
    }
    printf("\n");

    return 0;
}

/*
 * Spaja listu 1 s listom 2 na poziciji pos.
 * Argument pos mora imati vrijednost manju ili jednaku duljini liste head2.
 */
int connect(node *head1, node *head2, int pos) {
    node *t1, *t2;
    if (head1==NULL || head2==NULL) return -1;

    t1 = head1;
    while (t1->next) t1 = t1->next;
    // t1 je sada zadnji element liste 1
    t2 = head2;
    while (t2->next && pos>1) {
        t2 = t2->next;
        pos--;
    }
    // t2 je sada zadnji ili/i pos-ti element liste 2
    if (pos>1) return -1;  // ako nije pos-ti lista je prekratka
    t1->next = t2;  // spoji zadnji element liste 1 s pos-tim elementom liste 2

    return 0;
}

node *find_connection(node *head1, node *head2) {
    if (head1 == NULL || head2 == NULL) {
        return NULL;
    }

    node *t1, *t2;
    int n1 = 0, n2 = 0;

    t1 = head1;
    while(t1 != NULL) {
        t1 = t1->next;
        n1++;
    }

    t2 = head2;
    while(t2 != NULL) {
        t2 = t2->next;
        n2++;
    }

    t1 = head1;
    t2 = head2;
    //DEBUG("%d %d\n", n1, n2);

    while (n1 != n2) {
        //DEBUG("%d %d\n", t1->val, t2->val);
        if (n1 > n2) {
            t1 = t1->next;
            n1--;
        } else {
            t2 = t2->next;
            n2--;
        }
        //DEBUG("\n%d %d\n", n1, n2);
        //DEBUG("%d %d\n", t1->val, t2->val);
    }
    while (n1) {
        if (t1 == t2) return t1;
        t1 = t1->next;
        t2 = t2->next;
        n1--;
    }

    return NULL;
}

int main() {
    node *head[2] = { NULL, NULL }, *connection;
    char menu_choice;
    int i, pos, val, retval;

    do {
        //DEBUG("\n(d) dodaj - add\n(i) ispisi - print\n(c) spoji - connect\n(n) nadji spoj - find_connection\n(e) Exit\n");

        scanf(" %c", &menu_choice);
        switch (menu_choice) {
            case 'd':
                //DEBUG("Lista(1/2): ");
                scanf("%d", &i);
                //DEBUG("Vrijednost: ");
                scanf("%d", &val);
                retval = add(&head[--i], val);
                if (retval==-1) printf("Alokacija nije uspjela.\n");
                break;
            case 'i':
                //DEBUG("Lista(1/2): ");
                scanf("%d", &i);
                retval = print(head[--i]);
                if (retval==-1) printf("Lista je prazna.\n");
                break;
            case 'c':
                //DEBUG("Pozicija spoja: ");
                scanf("%d", &pos);
                retval = connect(head[0], head[1], pos);
                if (retval==-1) printf("Liste se ne mogu se spojiti na poziciji %d.\n", pos);
                break;
            case 'n':
                connection = find_connection(head[0], head[1]);
                if (connection==NULL) printf("Liste su prazne ili nisu povezane.\n");
                else printf("%d\n", connection->val);
                break;
        }
    } while(menu_choice!='e');

    return 0;
}

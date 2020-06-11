#include <stdio.h>
#include <stdlib.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

#define SIZE 8

struct array_s {
    int array[SIZE];
    int size;
} array_init = { .size=0 };
typedef struct array_s array_t;

typedef struct Node {
    struct Node *next;
    int val;
} node;

int insert(array_t *arr, int val) {
    if (arr->size==SIZE) return -1;
    arr->array[arr->size++] = val;
    return 0;
}

node *create_list(array_t arr, int i) {
    node *novo;
    if (i == arr.size) {
        return NULL;
    }

    novo = malloc(sizeof(node));
    novo->val = arr.array[i];
    novo->next = create_list(arr, ++i);
    return novo;
    
}

int print(node *head) {
    node *t;

    if (head==NULL) return -1;
    printf("Lista: ");
    for(t=head; t!=NULL; t=t->next) {
       printf("%d ", t->val);
    }
    printf("\n");
    return 0;
}

int main() {
    array_t arr = array_init;
    node *head=NULL;
    char menu_choice;
    int val, retval;

    do {
        //DEBUG("\n(d) dodaj \n(k) keriraj listu\n(i) ispis\n(e) Exit\n");

        scanf(" %c", &menu_choice);
        switch (menu_choice) {
            case 'd':
                scanf("%d", &val);
                retval = insert(&arr, val);
                if (retval==-1) printf("Polje je puno.\n");
                break;
            case 'k':
                head = create_list(arr, 0);
                break;
            case 'i':
                retval = print(head);
                if (retval==-1) printf("Lista je prazna.\n");
                break;
        }
    } while(menu_choice!='e');
    return 0;
}
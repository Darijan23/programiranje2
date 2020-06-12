#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

#define MAX_TREE_STRING 100

typedef struct Node {
    char val;
    struct Node *next;
} node;

node *create_list(char *list_string) {
    node *trenutni=NULL, *novi=NULL, *head;
    int i;

    for(i=0; i<strlen(list_string); i++) {
        novi = (node *)malloc(sizeof(node));
        novi->val = list_string[i];
        novi->next = NULL;
        if (!trenutni) head = novi;
        else trenutni->next = novi;
        trenutni = novi;
    }
    return head;
}

int print_list(node *head) {
    node *trenutni;

    if(!head) return -1;
    for(trenutni=head; trenutni!=NULL; trenutni=trenutni->next)
        printf("%c ", trenutni->val);
    printf("\n");
    return 0;
}

// nalazi n-ti element od pocetka liste, ako se želi prvi element za n staviti 1 itd.
node *nadji_s_pocetka(node *head, int n) {
    node *nti=head, *trenutni=NULL;
    int i=1;

    if (head==NULL) return NULL;
    for (trenutni=head; trenutni!=NULL; trenutni=trenutni->next, i++) {
        if (i==n) break;
        else if (i<n) nti = nti->next;
    }
    return nti;
}

// napisati funkciju koja pronalazi prvi element i iza njega ubacuje novi element
void ubaci_iza_prvog(node *head, char c) {
    node *trenutni, *novi = malloc(sizeof(node));
    novi->val = c;
    novi->next = NULL;

    if (head == NULL) {
        return;
    }

    trenutni = nadji_s_pocetka(head, 1);
    
    if (trenutni->next != NULL) {
        trenutni = trenutni->next;
        novi->next = trenutni;   
    }

    head->next = novi;
}

int main () {
    node *head=NULL;
    int menu_choice;
    char c, val, list_string[MAX_TREE_STRING];

    setbuf(stdout, NULL);
    do {
        menu_choice = 0;
        //DEBUG("\n1 Kreiraj listu \n2 Ispis");
        //DEBUG("\n3 Ubaci iza prvog");
        //DEBUG("\n4 Izlaz\n");
        scanf("%d", &menu_choice);
        switch (menu_choice) {
            case 1:
                if (head) {
                    //DEBUG("Lista vec postoji.\n");
                    break;
                }
                //DEBUG("Unesite listu kao niz znamenki bez razmaka: ");
                scanf(" %s", list_string);
                head = create_list(list_string);
                break;
            case 2:
                print_list(head);
                break;
            case 3:
                scanf(" %c", &val);
                ubaci_iza_prvog(head, val);
                break;
            case 4:
                break;
            default:
                while((c=getchar())!='\n' && c!=EOF);
        }
    } while(menu_choice!=4);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

#define MAX_SIZE 10

int max_rec(int *polje, int N) {
    int max = 0;

    if (N == 1) {
        return 0;
    }

    max = max_rec(polje + 1, N - 1) + 1;

    if (*polje > *(polje + max)) {
        return 0;
    }

    return max;
}

void sort_rec(int *polje, int N) {
    int max = 0, temp;

    if (N == 1) {
        return;
    }

    max = max_rec(polje, N);

    temp = *(polje + max);
    *(polje + max) = *polje;
    *polje = temp;

    sort_rec(polje + 1, N - 1);
}

void print_array(int array[], int size) {
    int i;

    for (i=0; i<size; i++) printf ("%d ",array[i]);
    printf("\n");
}

int main() {
    int array[MAX_SIZE];
    int i = 0;

    for (i=0; i<MAX_SIZE; i++) {
        scanf("%d", array+i);
    }
    printf("%d\n", max_rec(array, MAX_SIZE));
    sort_rec(array, MAX_SIZE);
    print_array(array, MAX_SIZE);
    return 0;
}
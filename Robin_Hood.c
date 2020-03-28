#include <stdio.h>
#include <math.h>

typedef struct {
    int r;
    int hit;
}meta;

int inside(double d, double r){
    return (d <= r);
}

void sort(meta array[], int size){
    for(int i = 0; i < size - 1; i++){
        int min = i;
        for(int j = i + 1; j < size; j++){
            if(array[min].r > array[j].r){
                min = j;
            }
        }

        meta tmp = array[min];
        array[min] = array[i];
        array[i] = tmp;
    }
}

double distance(int x, int y){
    return sqrt(x * x + y * y);
}


int main(){
    int n, m, x, y;
    double d;
    meta t[100];

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &t[i].r);
        t[i].hit = 0;
    }

    sort(t, n);

    scanf("%d", &m);

    for(int i = 0; i < m; i++){
        scanf("%d %d", &x, &y);

        d = distance(x, y);

        int j = 0;

        while(j < n && !inside(d, t[j].r)){
            j++;
        }

        if(j < n){
            t[j].hit++;
        }
    }

    for(int i = 0; i < n; i++){
        printf("%d ", t[i].hit);
    }

    return 0;
}
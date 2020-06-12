#include <stdio.h>
#include <math.h>

#define SIZE 100

//ovdje napisite funkciju
void swap(int *a, int n) {
    int temp, h;
    if (n % 2) {
        h = n / 2 + 1;
    } else {
        h = n / 2;
    }
    
    for (int i = 0; i < n / 2; i++) {        
        temp = *(a + i + h);
        *(a + i + h) = *(a + i);
        *(a + i) = temp;
    }    
}

int main(int argc, char const *argv[]){
	int n = 0, niz[SIZE];

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &niz[i]);
	}

	//ovdje pozovite funkciju
    swap(niz, n);

	for (int i = 0; i < n; i++) {
		printf("%d ", niz[i]);
	}

	return 0;
}
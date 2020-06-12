#include <stdio.h>
#include <stdlib.h>

#ifndef DEBUG
#define DEBUG(...)printf(__VA_ARGS__)
#endif

//ovdje napisite funkciju
void findmin(int **mat, int n, int m) {
    int min = 1001;
    int minin = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (*(*(mat + i) + j) < min) {
                min = *(*(mat + i) + j);
                minin = i * m + (j + 1);
            }            
        }        
    }

    printf("Najmanji element je: %d, na poziciji: %d", min, minin);
}

int main (){
	int br_red, br_stup;
	scanf("%d %d", &br_red, &br_stup);
	int **mat;
	mat = malloc(br_red * sizeof(int *));
	for (int i = 0; i < br_red; ++i) {
		*(mat+i) = malloc(sizeof(int) * br_stup);
	}

	for (int i = 0; i < br_red; i++) {
		for (int j = 0; j < br_stup; j++) {
			scanf("%d", &mat[i][j]); //ovako ne smijete
		}
	}

	//ovdje pozovite funkciju
    findmin(mat, br_red, br_stup);
	
	for (int i = 0; i < br_red; ++i) {
    	free(mat[i]);
  	}

  	free(mat);

	return 0;
}
#include <stdio.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

void load_data(int input[], int n) {
	for (int i = 0; i < n; ++i) {
		scanf("%d ", &input[i]);
	}
}

void counting_sort(int array[], int red[], int n){
	for (int i = 0; i < n; ++i) {
		red[array[i]]++;
	}
}

int main() {
	int proizvodi[1001] = {0}, vrijednosti[1001] = {0}, n, k;
	scanf("%d ", &n);
	load_data(proizvodi, n);
	scanf("%d ", &k);
	counting_sort(proizvodi, vrijednosti, n);

	int max = 0;
	for (int i = 0; i < k; ++i) {
		for (int j = 1; j < 1000; ++j) {
			if (vrijednosti[j] > vrijednosti[max]){
				max = j;
			}
		}
		printf("%d\n", max);
		vrijednosti[max] = 0;
		max = 0;
	}
	
	return 0;
}
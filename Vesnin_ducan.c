#include <stdio.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

int load_data(int input[]) {
	int n = 0;
	int a = 1;
	while (a != 0) {
		scanf("%d ", &a);
		input[n] = a;
		n++;
	}
	return n;
}

void counting_sort(int array[], int red[], int n){
	for (int i = 0; i < n; ++i) {
		red[array[i]]++;
	}
}

int main() {
	int proizvodi[11], prodano[10001], out[11], n;
	n = load_data(prodano);
	for (int i = 0; i <= 10; ++i) {
		proizvodi[i] = 0;
	}
	counting_sort(prodano, proizvodi, n);

	int max = 0;
	for (int i = 0; i <= 10; ++i) {
		for (int j = 1; j <= 10 ; ++j) {
			if (proizvodi[j] > proizvodi[max]){
				max = j;
			}
		}
		if (max != 0) {
			printf("%d\t", max);
			out[i] = proizvodi[max];
		}
		proizvodi[max] = 0;
		max = 0;
	}

	printf("\n");

	for (int i = 0; i <= 10; ++i) {
		if (out[i]) {
			printf("%d\t", out[i]);
		}
	}
	
	return 0;
}
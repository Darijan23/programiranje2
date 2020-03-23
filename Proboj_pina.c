#include <stdio.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

void load_data(int input[], int n) {
	for (int i = 0; i < n; ++i) {
		scanf("%d ", &input[i]);
	}
}

void insertion_sort(int array[], int n){
	for (int i = 0; i < n; ++i) {
		int t = array[i];
		int j = i;
		while (j > 0 && array[j - 1] > t) {
			array[j] = array[j - 1];
			j--;
		}

		array[j] = t;
	}
}

int main() {
	int polje[500], n;
	scanf("%d ", &n);
	load_data(polje, n);
	insertion_sort(polje, n);
	int p = n / 2;
	printf("%d\t%d\t%d", polje[p - 1], polje[p], polje[p + 1]);
	return 0;
}
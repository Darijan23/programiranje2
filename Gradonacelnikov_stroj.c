#include <stdio.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

int load_data(int input[], char c) {
	int n;
	switch(c) {
		case 'S':
			n = 20;
			break;

		case 'M':
			n = 32;
			break;

		case 'T':
			n = 40;
			break;

		case 'N':
			n = 52;
			break;
	}

	for (int i = 0; i < n; ++i) {
		scanf("%d ", &input[i]);
	}

	return n;
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
	int spil[52], n, k;
	char c;
	scanf("%d ", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%c ", &c);
		k = load_data(spil, c);
		insertion_sort(spil, k);
		for (int j = 0; j < k; ++j) {
			printf("%d ", spil[j]);
		}
		printf("\n");
	}
	return 0;
}
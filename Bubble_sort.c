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
	return n - 1;
}

void bubble_sort(int polje[], int n) {
	int t;
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j < n; ++j) {
			if (polje[j - 1] < polje[j]) {
				t = polje[j - 1];
				polje[j - 1] = polje[j];
				polje[j] = t;
			}
		}
	}
}

int main() {
	int brojevi[10000], n;
	n = load_data(brojevi);
	bubble_sort(brojevi, n);

	for (int i = 0; i < n; ++i) {
		printf("%d ", brojevi[i]);
	}

	return 0;
}
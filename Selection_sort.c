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

void selection_sort(int polje[], int n){
	for (int i = 0; i < n; ++i) {
		int min = i;
		for (int j = i + 1; j < n; ++j) {
			if (polje[min] > polje[j]) {
				min = j;
			}
		}
		
		int t = polje[min];
		polje[min] = polje[i];
		polje[i] = t;
	}
}

int main() {
	int polje[10000], n;
	n = load_data(polje);
	selection_sort(polje, n);
	for (int i = 0; i < n; ++i) {
		printf("%d ", polje[i]);
	}
	return 0;
}
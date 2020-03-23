#include <stdio.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif


void selection_sort(int polje[], int n){
	for (int i = 0; i < n; ++i) {
		int max = i;
		for (int j = i + 1; j < n; ++j) {
			if (polje[max] < polje[j]) {
				max = j;
			}
		}
		
		int t = polje[max];
		polje[max] = polje[i];
		polje[i] = t;
	}
}

int main() {
	int meduze[100], n;
	scanf("%d ", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d ", &meduze[i]);
		int m = meduze[i];
		selection_sort(meduze, i+1);
		for (int j = 0; j < i+1; ++j) {
			if (meduze[j] == m) {
				printf("%d\n", j+1);
				break;
			}
		}
		for (int j = 0; j < i+1; ++j) {
			printf("%d ", meduze[j]);
		}
		printf("\n");
	}
	return 0;
}
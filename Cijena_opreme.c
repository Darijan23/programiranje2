#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

typedef struct {
	char name[128];
	int price;	
} product;


void prosort(product prd[], int n, char k, char s) {
	char tip[3];
	tip[0] = k;
	tip[1] = s;
	if (!strcmp(tip, "IU")) {
		for (int i = 0; i < n - 1; ++i) {
			int pos = i;
			for (int j = i + 1; j < n; ++j) {
				if (strcmp(prd[pos].name, prd[j].name) > 0) {
					pos = j;
				} else if (!strcmp(prd[pos].name, prd[j].name)) {
					if (prd[pos].price > prd[j].price) {
						pos = j;
					}
				}
			}
			product temp = prd[pos];
			prd[pos] = prd[i];
			prd[i] = temp;
		}
	} else if (!strcmp(tip, "IS")) {
		for (int i = 0; i < n - 1; ++i) {
			int pos = i;
			for (int j = i + 1; j < n; ++j) {
				if (strcmp(prd[pos].name, prd[j].name) < 0) {
					pos = j;
				} else if (!strcmp(prd[pos].name, prd[j].name)) {
					if (prd[pos].price < prd[j].price) {
						pos = j;
					}
				}
			}
			product temp = prd[pos];
			prd[pos] = prd[i];
			prd[i] = temp;
		}
	} else if (!strcmp(tip, "CU")) {
		for (int i = 0; i < n - 1; ++i) {
			int pos = i;
			for (int j = i + 1; j < n; ++j) {
				if (prd[pos].price > prd[j].price) {
					pos = j;
				} else if (prd[pos].price == prd[j].price) {
					if (strcmp(prd[pos].name, prd[j].name) > 0) {
						pos = j;
					}
				}
			}
			product temp = prd[pos];
			prd[pos] = prd[i];
			prd[i] = temp;
		}
	} else {
		for (int i = 0; i < n - 1; ++i) {
			int pos = i;
			for (int j = i + 1; j < n; ++j) {
				if (prd[pos].price < prd[j].price) {
					pos = j;
				} else if (prd[pos].price == prd[j].price) {
					if (strcmp(prd[pos].name, prd[j].name) < 0) {
						pos = j;
					}
				}
			}
			product temp = prd[pos];
			prd[pos] = prd[i];
			prd[i] = temp;
		}
	}
}


int main() {
	char krit, smjer;
	int n;
	product stock[100];

	scanf("%d ", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%127s %d ", stock[i].name, &stock[i].price);
	}

	
	scanf("%c %c", &krit, &smjer);
	prosort(stock, n, krit, smjer);

	for (int i = 0; i < n; ++i) {
		printf("%s\t%5d\n", stock[i].name, stock[i].price);
	}

	return 0;
}
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

int main() {
	int n;
	char unos[100][256];
	int slova = 0, velika = 0, mala = 0, znam = 0, raz = 0, ost = 0;
	scanf("%d ", &n);
	for (int i = 0; i < n; ++i)	{
		scanf("%[^\n]%*c",unos[i]);
		int l = strlen(unos[i]);
		for (int j = 0; j < l; ++j) {
			if (isalpha(unos[i][j])) {
				slova++;
				if (islower(unos[i][j])) {
					mala++;
				} else {
					velika++;
				}
			} else if (isdigit(unos[i][j])) {
				znam++;
			} else if (unos[i][j] == ' ') {
				raz++;
			} else if(ispunct(unos[i][j])){
				ost++;
			}
		}
	}
	printf("%d %d %d\n%d %d %d", slova, velika, mala, znam, raz, ost);

	return 0;
}

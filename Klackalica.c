#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

int main() {
	char plank[101];
	scanf("%[^\n]\n", plank);
	int l = 0, d = 0, i = 0;
	while (plank[i] != 'B') {
		if (plank[i] == 'S') {
			l++;
		}
		i++;
	}
	strcpy(plank, strstr(plank, "B"));
	i = 0;
	while (plank[i] != '\0') {
		if (plank[i] == 'S') {
			d++;
		}
		i++;
	}

	if (l > d) {
		printf("Lijevo");
	} else if (d > l) {
		printf("Desno");
	} else {
		printf("Ravnoteza");
	}

	return 0;
}

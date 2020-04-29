#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

const char COLS[6][20] = {"Bijela", "Crvena", "Narancasta", "Plava", "Zelena", "Zuta"};

void check_colors(char (*cube)[3][3]) {
	int solved = 1;
	int sides[6] = {0};
	for (int i = 0; i < 6; i++) {
		int side = 1;
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (*(*(*(cube + i) + j) + k) != *(*(*(cube + i) + 1) + 1)) {
					side = 0;
				}
			}
		}

		if (!side) {
			solved = 0;
			switch (*(*(*(cube + i) + 1) + 1)) {
				case 'W':
					sides[0] = 1;
					break;
				case 'R':
					sides[1] = 1;
					break;
				case 'O':
					sides[2] = 1;
					break;
				case 'B':
					sides[3] = 1;
					break;
				case 'G':
					sides[4] = 1;
					break;
				case 'Y':
					sides[5] = 1;
					break;
			}
		}
	}
	if (solved) {
		printf("Kocka je slozena");
	} else {
		for (int i = 0; i < 6; i++) {
			if (sides[i]) {
				printf("%s\n", COLS[i]);
			}
		}
	}
}

int main() {
	char kocka[6][3][3];

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				scanf("%c ", &kocka[i][j][k]);
			}
		}
		scanf("\n");
	}

	check_colors(kocka);

    return 0;
}
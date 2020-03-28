#include <stdio.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

typedef struct {
	int x, y, z;
} vektor;

int main() {
	vektor skup[3];
	int det;

	for (int i = 0; i < 3; ++i) {
		scanf("%d %d %d ", &skup[i].x, &skup[i].y, &skup[i].z);
	}

	det = skup[0].x * skup[1].y * skup[2].z + skup[2].x * skup[0].y * skup[1].z  + skup[1].x * skup[2].y * skup[0].z - skup[2].x * skup[1].y * skup[0].z - skup[0].x * skup[2].y * skup[1].z - skup[1].x * skup[0].y * skup[2].z;

	if (det) {
		printf("NE");
	} else {
		printf("DA");
	}
	return 0;
}
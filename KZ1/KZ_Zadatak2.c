#include <stdio.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

#define MAX 6

typedef struct {
	char name[30];
	int positive;
	int negative;
} Spell;

void play(Spell s[], int p, int op, int n) {
	//napisati dio koda koji ispisuje "Spell" karte koje su preporucene igracu
	//i krajnju uspjesnost
	for (int i = 0; i < n; i++) {
		if (p - s[i].negative >= 1)	{
			op -= s[i].positive;
			p -= s[i].negative;
			printf("%s\n", s[i].name);
		}
		if (op <= 0) {
			printf("Uspjesno");
			break;
		}
	}
	if (op > 0) {
		printf("Neuspjesno, protivnik ima: %d zivotnih bodova\n", op);
	}
}

int main() {
	Spell spells[MAX];
	int size = 0; //broj karata
	int player, opponent; // igracevi i protivnikovi zivotni bodovi

	scanf("%d\n", &size);

	//napisati dio koda za unos karata i zivotnih bodova
	for (int i = 0; i < size; i++) {
		scanf("%s %d %d\n", spells[i].name, &spells[i].positive, &spells[i].negative);
	}
	scanf("%d %d ", &opponent, &player);

	//napisati poziv funkcije play
	play(spells, player, opponent, size);

	return 0;
}
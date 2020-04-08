/*
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

int main() {
	int n;
	char ime[128], prezime[128];
	char sime[128], sprez[128];

	scanf("%s %s ", sime, sprez);
	scanf("%d ", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%s %s ", ime, prezime);
		if (!strncmp(ime, sime, strlen(sime)) && !strncmp(prezime, sprez, strlen(sprez))) {
			printf("%s, %s\n", prezime, ime);
		}
	}

	return 0;
}
*/

#include <stdio.h>
#include <string.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

typedef struct {
  char ime[16];
  char prezime[16];
} student;

// Napisati funkciju koja provjerava da li ime i prezime studenta s pocinju sa zadanim dijelom imena i prezimena iz search-a
// Funkcija vraca 1 ako pocinju i 0 ako ne pocinju
int check_name(student p, student s) {
	return !strncmp(p.ime, s.ime, strlen(p.ime)) && !strncmp(p.prezime, s.prezime, strlen(p.prezime));
}

int main() {
  int n;
  student search;
  student s[32];

  scanf("%s %s", search.ime, search.prezime);

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%s %s", s[i].ime, s[i].prezime);
  }

  // Napisati dio koda za prolazak kroz sve studente, pretragu i ispis
  for (int i = 0; i < n; ++i) {
  	if (check_name(search, s[i])) {
  		printf("%s, %s\n", s[i].prezime, s[i].ime);
  	}
  }

  return 0;
}

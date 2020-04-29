#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

#define SIZE 512     



// funkcija vraca slovo iz retka iza znaka '+' ili razmak ako je znak u retku '-'
char pronadjiZnak(char rijec[]) {
	char c;
	for (int i = 0; i < strlen(rijec); i++) {
		if (rijec[i] == '+') {
			c = rijec[i + 1];
		} else if (rijec[i] == '-') {
			c = ' ';
		}
	}
	return c;
}



int main() {   
	char line[128], str[128];
	int zb = 0, tmp;
 
  // otvaranje datoteke
	FILE *fp;
	fp = fopen("input.dat", "r");
	


  // citanje i ispis skrivene porkue
	while (fscanf(fp, "%[^\n]\n", line) > 0) {
		sscanf(line, "%[^ ] %d", str, &tmp);
		if (!(tmp / 10)) {
			zb += tmp;
		}
		printf("%c", pronadjiZnak(line));
	}


  printf("\n");



  // ispis zbroja jednoznamenkastih brojeva
  	printf("%d", zb);
 	


  // zatvaranje datoteke
  	fclose(fp);
 

  return 0;
}
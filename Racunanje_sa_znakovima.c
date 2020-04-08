#include <stdio.h>
#include <string.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

// Napisati funkciju koja vraća operatore matematičkih operacija temeljem unesenog znakovnog niza
char get_operator(char o[]) {
	if (!strcmp(o, "plus")) {
		return '+';
	} else if (!strcmp(o, "minus")) {
		return '-';
	} else if (!strcmp(o, "puta")) {
		return '*';
	} else if (!strcmp(o, "podijeljeno")) {
		return '/';
	}
	return '%';
}

// Napisati funkciju koja vraća operande matematičkih operacija temeljem unesenog znakovnog niza
int get_operand(char n[]) {
	if (!strcmp(n, "nula")) {
		return 0;
	} else if (!strcmp(n, "jedan")) {
		return 1;
	} else if (!strcmp(n, "dva")) {
		return 2;
	} else if (!strcmp(n, "tri")) {
		return 3;
	} else if (!strcmp(n, "cetiri")) {
		return 4;
	} else if (!strcmp(n, "pet")) {
		return 5;
	} else if (!strcmp(n, "sest")) {
		return 6;
	} else if (!strcmp(n, "sedam")) {
		return 7;
	} else if (!strcmp(n, "osam")) {
		return 8;
	} else if (!strcmp(n, "devet")) {
		return 9;
	} 
	return -1;
}

int calculate_operation(char a[], char b[], char o[]) {
  switch(get_operator(o)) {
    case '+':
      return get_operand(a) + get_operand(b);
    case '-':
      return get_operand(a) - get_operand(b);
    case '*':
      return get_operand(a) * get_operand(b);
    case '/':
      return get_operand(a) / get_operand(b);
    case '%':
      return get_operand(a) % get_operand(b);
  }
  return -1;
}

int main() {
  char a[16], b[16], o[16];

  scanf("%s %s %s", a, o, b);

  printf("%d", calculate_operation(a, b, o));

  return 0;
}

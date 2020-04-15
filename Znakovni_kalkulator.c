#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

// Napisati funkciju koja cisti string od nepotrebnih znakova
void clean_string(char s[]) {
  int i, n = 0;

  for (i = 0; i < strlen(s); ++i) {
    s[i - n] = tolower(s[i]);
    if (!isalpha(s[i])) {
      n++;
    }
  }
  s[i - n] = '\0';
}

char get_operator(char o[]) {
  if (!strcmp("plus", o)) {
    return '+';
  }

  if (!strcmp("minus", o)) {
    return '-';
  }

  if (!strcmp("puta", o)) {
    return '*';
  }

  if (!strcmp("podijeljeno", o)) {
    return '/';
  }

  if (!strcmp("modulo", o)) {
    return '%';
  }

  return -1;
}

int get_operand(char n[]) {
  char numbers[10][16] = {"nula", "jedan", "dva", "tri", "cetiri", "pet", "sest", "sedam", "osam", "devet"};

  for (int i = 0; i < 10; i++) {
    if (!strcmp(numbers[i], n)) {
      return i;
    }
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
  int n;
  char a[64], b[64], o[64];

  scanf("%d", &n);

  // Deklaracija i otvaranje datoteke
  FILE *fp;
  fp = fopen("input.dat", "r");

  // Procitati sadrzaj datoteke i ispisati rezultat operacije
  for (int i = 0; i < n; i++) {
    fscanf(fp, "%s %s %s", a, o, b);
    clean_string(a);
    clean_string(b);
    clean_string(o);
    printf("%d ", calculate_operation(a, b, o));
  }

  // Zatvoriti datoteku
  fclose(fp);

  return 0;
}

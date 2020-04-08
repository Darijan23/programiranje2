#include <stdio.h>
#include <string.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

#define M 256

// Napisati funkciju za provjeru radi li se o palindromu
int check_palindrome(char s[]) {
	int n = strlen(s) - 1, uvjet = 1;
	for (int i = 0; i < n; ++i) {
		if (s[i] != s[n - i]) {
			uvjet = 0;
			break;
		}
	}

	return uvjet;
}

int main() {
  char str[M];

  scanf("%s", str);

  // Napisati dio koda koji brise znakove dok god se radi o palindromu

  while	(strlen(str) > 0 && check_palindrome(str)) {
  	str[strlen(str) - 1] = '\0';
  }

  printf("%d", (int) strlen(str));

  return 0;
}
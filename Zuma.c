#include <stdio.h>
#include <stdlib.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

int main() {
	int l, n;
	char *s;
	scanf("%d ", &l);
	l++;

	s = malloc(l * sizeof(char));
	scanf("%s ", s);
	scanf("%d ", &n);

	for (int i = 0; i < n; i++) {
		char b;
		int p;
		scanf("%c %d ", &b, &p);
		l++;
		s = realloc(s, l * sizeof(char));

		for (int j = l - 1; j >= p - 1; j--) {
			s[j + 1] = s[j];
		}
		s[p - 1] = b;
		int le = p - 1;

		while(le > 0 && s[le - 1] == b) {
			le--;
		}

		int ri = p - 1;

		while(ri < l - 1 && s[ri + 1] == b) {
			ri++;
		}

		int d = ri - le + 1;

		if (d >= 3)	{
			for (int j = ri + 1; j < l; j++) {
				s[j - d] = s[j];
			}
			l -= d;
			s = realloc(s, l * sizeof(char));
		}
		printf("%s\n", s);
	}

	free(s);

    return 0;
}

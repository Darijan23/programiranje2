#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

int main() {
	char line[256];
	scanf("%[^\n]\n", line);
	int  c = 1;
	line[0] = toupper(line[0]);
	for (int i = 1; i < strlen(line); ++i) {
		if (line[i] == ' ') {
			c++;
			line[i + 1] = toupper(line[i + 1]);
			int j = 2;
			while (line[i + j] != ' ' && i + j < strlen(line)) {
				line[i + j] = tolower(line[i + j]);
				j++;
			}
		}
	}
	printf("%d\n%s", c, line);

	return 0;
}
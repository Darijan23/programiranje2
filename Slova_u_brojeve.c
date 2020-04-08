#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

int tonum(char in[]) {
	int out;

	if (!strcmp(in, "nula")) {
		out = 0;
	} else if (!strcmp(in, "jedan")) {
		out = 1;
	} else if (!strcmp(in, "dva")) {
		out = 2;
	} else if (!strcmp(in, "tri")) {
		out = 3;
	} else if (!strcmp(in, "cetiri")) {
		out = 4;
	} else if (!strcmp(in, "pet")) {
		out = 5;
	} else if (!strcmp(in, "sest")) {
		out = 6;
	} else if (!strcmp(in, "sedam")) {
		out = 7;
	} else if (!strcmp(in, "osam")) {
		out = 8;
	} else if (!strcmp(in, "devet")) {
		out = 9;
	} else {
		out = -1;
	}
	return out;
}

int main() {
	char line[256];

	scanf("%[^\n]\n", line);

	while (line[0] != '_') {
		char num[256] = {'\0'};
		float out = 0.0;
		int j = 0;

		for (int i = 0; i <= strlen(line); ++i) {
			if (line[i] == '_' || i == strlen(line)) {
				out *= 10;
				out += tonum(num);
				int n = strlen(num);
				for (int k = 0; k < n; ++k) {
					num[k] = '\0';
				}
				j = 0;
			} else if (isalpha(line[i])) {
				num[j] = tolower(line[i]);
				j++;
			}
		}
		printf("%.2f\n", out / 2);
		scanf("%[^\n]\n", line);
	}

	return 0;
}

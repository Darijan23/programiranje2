#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif


int main() {
	int mp3 = 0, mp4 = 0, txt = 0, ost = 0;
	char ime[256], suf[32];

	FILE *fp;
	fp = fopen("input.dat", "r");

	while (!feof(fp)) {
		fscanf(fp, "%[^.].%s\n", ime, suf);
		if (!strcmp(suf, "mp3")) {
			mp3++;
		} else if (!strcmp(suf, "mp4")) {
			mp4++;
		} else if (!strcmp(suf, "txt")) {
			txt++;
		} else {
			ost++;
		}
	}

	printf("%d\n%d\n%d\n%d", mp3, mp4, txt, ost);

	return 0;
}

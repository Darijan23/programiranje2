#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif


typedef struct {
	char c;
	int pon;
	float uc;
} znak;

int main() {
	znak znakovi[256];
	int nz = 0;

	return 0;
}
#include <stdio.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

int visekratnik(int a, int b, int nzv) {
	if (nzv % b != 0) {
		return visekratnik(a, b, nzv + a);
	}

	return nzv;
}

int main(){
    int a, b, nzv;

    DEBUG("Unesite dva broja: ");
    scanf("%d%d", &a, &b);
    // ovdje pozvati funkciju koja vraca nzv

    if (a < b) {
    	nzv = visekratnik(a, b, a);
	} else {
		nzv = visekratnik(b, a, b);
	}

    printf("Najmanji zajednicki visekratnik brojeva %d i %d je %d.", a, b, nzv);
    return 0;
}
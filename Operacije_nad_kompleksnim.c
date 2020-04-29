#include <stdio.h>
#include <math.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

typedef struct {
	float re, im;
} cmplx;

void calc(cmplx z1, cmplx z2, cmplx *s, cmplx *d, cmplx *p, cmplx *q) {
	s->re = z1.re + z2.re;
	s->im = z1.im + z2.im;

	d->re = z1.re - z2.re;
	d->im = z1.im - z2.im;

	p->re = z1.re * z2.re - z1.im * z2.im;
	p->im = z1.re * z2.im + z1.im * z2.re;

	q->re = (z2.re * z1.re + z2.im * z1.im)/(pow(z2.re, 2) + pow(z2.im, 2));
	q->im = (z2.re * z1.im - z2.im * z1.re)/(pow(z2.re, 2) + pow(z2.im, 2));
}

int main() {
	cmplx z1, z2, sum, diff, prod, quot;

	scanf("%f %f %f %f ", &z1.re, &z1.im, &z2.re, &z2.im);

	calc(z1, z2, &sum, &diff, &prod, &quot);

	printf("%.2f\t%.2f\n", sum.re, sum.im);
	printf("%.2f\t%.2f\n", diff.re, diff.im);
	printf("%.2f\t%.2f\n", prod.re, prod.im);
	printf("%.2f\t%.2f\n", quot.re, quot.im);

	return 0;
}
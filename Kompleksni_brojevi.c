#include <stdio.h>
#include <math.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

typedef struct {
	float re, im;
} complex;

complex add (complex a, complex b) {
	complex out;
	out.re = a.re + b.re;
	out.im = a.im + b.im;
	return out;
}
complex subtract (complex a, complex b) {
	complex out;
	out.re = a.re - b.re;
	out.im = a.im - b.im;
	return out;
}
complex multiply (complex a, complex b) {
	complex out;
	out.re = a.re * b.re - a.im * b.im;
	out.im = a.re * b.im + a.im * b.re;
	return out;
}
complex divide (complex a, complex b) {
	complex out;
	out.re = (b.re * a.re + b.im * a.im)/(pow(b.re, 2) + pow(b.im, 2));
	out.im = (b.re * a.im - b.im * a.re)/(pow(b.re, 2) + pow(b.im, 2));
	return out;
}

int main() {
	complex a, b, r;
	char op;
	scanf("%f %f %f %f ", &a.re, &a.im, &b.re, &b.im);
	scanf("%c", &op);
	switch(op) {
		case '+':
			r = add(a, b);
			break;
		case '-':
			r = subtract(a, b);
			break;
		case '*':
			r = multiply(a, b);
			break;
		case '/':
			r = divide(a, b);
			break;
	}

	printf("%.2f\t%.2f", r.re, r.im);
	return 0;
}
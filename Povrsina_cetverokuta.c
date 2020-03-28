#include <stdio.h>
#include <math.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

typedef struct {
	float x;
	float y;
} point;

typedef struct {
	point a;
	point b;
	point c;
	point d;
	float opseg;
	float povrsina;
} cetverokut;

float dist(point a, point b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
	int uvjet = 1;
	point p, q; // vektori, ali sam ih definirao kao točke jer mi se nije dalo raditi još jednu strukturu
	cetverokut cet;

	while (uvjet) {
		scanf("%f %f %f %f %f %f %f %f ", &cet.a.x, &cet.a.y, &cet.b.x, &cet.b.y, &cet.c.x, &cet.c.y, &cet.d.x, &cet.d.y);
		if (dist(cet.a, cet.b) == 0 || dist(cet.a, cet.c) == 0 || dist(cet.a, cet.d) == 0 || dist(cet.b, cet.c) == 0 || dist(cet.b, cet.d) == 0 || dist(cet.c, cet.d) == 0) {
			uvjet = 0;
			break;
		} else {
			float a = dist(cet.a, cet.b), b = dist(cet.a, cet.d), c = dist(cet.b, cet.c), d = dist(cet.c, cet.d);
			cet.opseg = a + b + c + d;
			p.x = cet.c.x - cet.a.x;
			p.y = cet.c.y - cet.a.y;
			q.x = cet.d.x - cet.b.x;
			q.y = cet.d.y - cet.b.y;
			cet.povrsina = 0.5 * fabsf(p.x * q.y - q.x * p.y);
			printf("%.3f %.3f\n", cet.povrsina, cet.opseg);
		}
	}

	return 0;
}
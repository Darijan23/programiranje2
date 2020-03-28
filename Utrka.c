#include <stdio.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

typedef struct {
	int h;
	int m;
	float s;
} time;

typedef struct {
	float v;
	int p;
	int d;
	float rs;
	time r;
} racer;

float tdiff(racer t, int l) {
	float rs;
	rs = (float)l / t.v;
	if (t.d && t.p)	{
		for (int i = 0; i < l - t.p; i += t.p) {
			rs += t.d;
		}
	}
	return rs;
}

//ne zaokružuje, daje krivi rezultat u nekim slučajevima

time tconv(float t) {
	time out;
	out.h = (int)t / 3600.0;
	t -= 3600.0 * out.h;
	out.m = (int)t / 60.0;
	out.s = t - (float)(out.m * 60.0);
	return out; 
}

int main() {
	int len;
	racer a, b;

	scanf("%d ", &len);
	scanf("%f %d %d ", &a.v, &a.p, &a.d);
	scanf("%f %d %d ", &b.v, &b.p, &b.d);

	a.rs = tdiff(a, len);
	b.rs = tdiff(b, len);

	a.r = tconv(a.rs);
	b.r = tconv(b.rs);

	printf("A = %02d:%02d:%02.2f\n", a.r.h, a.r.m, a.r.s);
	printf("B = %02d:%02d:%02.2f\n", b.r.h, b.r.m, b.r.s);

	if (a.rs < b.rs) {
		printf("A");
	} else if (a.rs > b.rs)	{
		printf("B");
	} else {
		printf("=");
	}

	return 0;
}
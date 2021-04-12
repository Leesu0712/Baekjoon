#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main() {
	double R, ans1, ans2;
	scanf("%lf", &R);

	ans1 = R * R * M_PI;
	ans2 = R * R * 2;

	printf("%lf\n%lf\n", ans1, ans2);

	return 0;
}

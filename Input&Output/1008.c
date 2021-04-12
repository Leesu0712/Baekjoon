#include <stdio.h>

int main() {
	double i, j;

	scanf("%lf %lf", &i, &j);
	printf("%.15g", i/j);

	return 0;
}

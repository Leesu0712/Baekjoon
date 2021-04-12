#include <stdio.h>

int main() {
	int i, j, a, b, c;

	scanf("%d %d", &i, &j);
	a = j/100;
	b = (j%100)/10;
	c = (j%100)%10;

	printf("%d\n%d\n%d\n%d\n", i*c, i*b, i*a, i*c + i*b*10 + i*a*100);

	return 0;
}

#include <stdio.h>

int main() {
	int a, b, i, min, max, gcd, lcm;
	scanf("%d %d", &a, &b);

	min = a < b ? a : b;
	max = a > b ? a : b;

	for(i = min; i > 0; i--) {
		if(!(a % i) && !(b % i)) {
			gcd = i;
			break;
		}
	}

	for(i = 1; i <= 10000; i++) {
		if(!((max * i) % min)) {
			lcm = max * i;
			break;
		}
	}

	printf("%d\n%d\n", gcd, lcm);
	return 0;
}

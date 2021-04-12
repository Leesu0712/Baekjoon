#include <stdio.h>

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	int N, i, ra, rb, d;
	scanf("%d", &N);
	scanf("%d", &ra);
	for(i = 1; i < N; i++) {
		scanf("%d", &rb);
		d = gcd(ra, rb);
		printf("%d/%d\n", ra/d, rb/d);
	}
	return 0;
}

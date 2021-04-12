#include <stdio.h>
#define NMAX 45000

int main() {
	int T, i, j, A, B, max, min, lcm;
	scanf("%d", &T);
	for(i = 0; i < T; i++) {
		scanf("%d %d", &A, &B);
		max = A > B ? A : B;
		min = A < B ? A : B;
		for(j = 1; j < NMAX; j++) {
			if(!((max * j) % min)) {
				lcm = max * j;
				break;
			}
		}
		printf("%d\n", lcm);
	}
	return 0;
}

#include <stdio.h>
#define NMAX 100000

int main() {
	int N, i;
	long long L[NMAX - 1], P[NMAX], min, cost;
	scanf("%d", &N);
	for(i = 0; i < N - 1; i++)
		scanf("%lld", &L[i]);
	for(i = 0; i < N; i++)
		scanf("%lld", &P[i]);

	cost = P[0] * L[0];
	min = P[0];
	for(i = 1; i < N - 1; i++) {
		if(min > P[i]) {
			cost += P[i] * L[i];
			min = P[i];
		}
		else
			cost += min * L[i];
	}

	printf("%lld\n", cost);

	return 0;
}

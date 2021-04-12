#include <stdio.h>
#define MAX 101

int main() {
	int T, N, i, j;
	long long A[MAX];
	scanf("%d", &T);
	A[0] = 0; A[1] = 1; A[2] = 1; A[3] = 1; A[4] = 2;
	for(i = 0; i < T; i++) {
		scanf("%d", &N);
		for(j = 5; j < N + 1; j++)
			A[j] = A[j - 5] + A[j - 1];
		printf("%lld\n", A[N]);
	}
	return 0;
}

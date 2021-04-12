#include <stdio.h>

int main() {
	int N, i, j, K, A[10], sum = 0, cnt = 0;
	scanf("%d %d", &N, &K);
	for(i = 0; i < N; i++)
		scanf("%d", &A[i]);

	for(i = N - 1; sum < K; i--) {
		if(sum + A[i] > K) {
			printf("%d + %d > %d, continue\n", sum, A[i], K);
			continue;
		}
		else {
			for(j = 1; sum + A[i] <= K; j++) {
				printf("sum = %d + %d\n", sum, A[i]);
				sum += A[i];
				cnt++;
			}
		}
	}

	printf("%d\n", cnt);

	return 0;
}

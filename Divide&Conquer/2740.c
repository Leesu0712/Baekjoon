#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main() {
	int N, M, K, i, j, k, A[MAX][MAX], B[MAX][MAX], C[MAX][MAX] = { 0, };
	scanf("%d %d", &N, &M);
	for(i = 0; i < N; i++)
		for(j = 0; j < M; j++)
			scanf("%d", &A[i][j]);
	scanf("%d %d", &M, &K);
	for(i = 0; i < M; i++)
		for(j = 0; j < K; j++)
			scanf("%d", &B[i][j]);

	for(i = 0; i < N; i++)
		for(k = 0; k < K; k++)
			for(j = 0; j < M; j++)
				C[i][k] += A[i][j] * B[j][k];

	for(i = 0; i < N; i++) {
		for(k = 0; k < K; k++)
			printf("%d ", C[i][k]);
		printf("\n");
	}

	return 0;
}

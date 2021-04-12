#include <stdio.h>
#include <stdlib.h>
#define MOD 1000

void printarr(int A[5][5], int N) {
	int i, j;
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++)
			printf("%d ", A[i][j]);
		printf("\n");
	}
}


int **mult(int **A, int **B, int N) {
	int i, j, k;
	int **arr = (int **)malloc(sizeof(int *) * N);
	for(i = 0; i < N; i++)
		arr[i] = (int *)malloc(sizeof(int) * N);

	for(i = 0; i < N; i++)
		for(k = 0; k < N; k++)
			for(j = 0; j < N; j++) {
				arr[i][k] += ((A[i][j] % MOD) * (B[j][k] % MOD) % MOD);
				arr[i][k] = arr[i][k] % MOD;
			}

	return arr;
}

int **power(int **A, int N, int B) {
	if(B == 1)
		return A;
	else if(B % 2) {
		return mult(power(A, N, B-1), A, N);
	}
	else {
		return mult(power(A, N, B/2), power(A, N, B/2), N);
	}
}

int main() {
	int N, B, i, j, **A;
	int **p;
	scanf("%d %d", &N, &B);
	A = (int **)malloc(sizeof(int *) * N);
	for(i = 0; i < N; i++)
		A[i] = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
			scanf("%d", &A[i][j]);

	p = power(A, N, B);

	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++)
			printf("%d ", p[i][j]);
		printf("\n");
	}

	for(i = 0; i < N; i++) {
		free(A[i]);
		free(p[i]);
	}
	free(A);
	free(p);

	return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main() {
	int N, i, j, tmp;
	int *A;
	scanf("%d", &N);
	A = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++)
		scanf("%d", &A[i]);

	for(j = N - 1; j > 0; j--) {
		for(i = 0; i < j; i++) {
			if(A[i] > A[i + 1]) {
				tmp = A[i + 1];
				A[i + 1] = A[i];
				A[i] = tmp;
			}
		}
	}
	for(i = 0; i < N; i++)
		printf("%d\n", A[i]);
	free(A);
	return 0;
}

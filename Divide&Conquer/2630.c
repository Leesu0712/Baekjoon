#include <stdio.h>
#include <stdlib.h>
#define NMAX 128

int White(int **A, int r, int c, int n) {
	int i, j, dv = 0;
	for(i = r; i < r + n; i++) {
		for(j = c; j < c + n; j++) {
			if(A[i][j]) {
				dv = 1;
				break;
			}
		}
	}
	if(!dv)
		return 1;
	else if(n == 1)
		return 0;
	else
		return White(A, r, c, n/2) + White(A, r, c+n/2, n/2) + White(A, r+n/2, c, n/2) + White(A, r+n/2, c+n/2, n/2);
}

int Blue(int **A, int r, int c, int n) {
	int i, j, dv = 0;
	for(i = r; i < r + n; i++) {
		for(j = c; j < c + n; j++) {
			if(!A[i][j]) {
				dv = 1;
				break;
			}
		}
	}
	if(!dv)
		return 1;
	else if(n == 1)
		return 0;
	else
		return Blue(A, r, c, n/2) + Blue(A, r, c+n/2, n/2) + Blue(A, r+n/2, c, n/2) + Blue(A, r+n/2, c+n/2, n/2);
}

int main() {
	int N, i, j, **P;
	scanf("%d", &N);
	P = (int **)malloc(sizeof(int *) * N);
	for(i = 0; i < N; i++) {
		P[i] = (int *)malloc(sizeof(int) * N);
		for(j = 0; j < N; j++)
			scanf("%d", &P[i][j]);
	}

	printf("%d\n%d\n", White(P, 0, 0, N), Blue(P, 0, 0, N));

	return 0;
}

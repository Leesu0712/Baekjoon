#include <stdio.h>
#include <stdlib.h>
#define NMAX 64

void QuadTree(int **A, int r, int c, int n) {
	int i, j, dot, dv = 0;
	dot = A[r][c];
	for(i = r; i < r + n; i++) {
		for(j = c; j < c + n; j++) {
			if(A[i][j] != dot) {
				dv = 1;
				break;
			}
		}
	}
	if(!dv)
		printf("%d", dot);
	else {
		printf("(");
		QuadTree(A, r, c, n/2);
		QuadTree(A, r, c+n/2, n/2);
		QuadTree(A, r+n/2, c, n/2);
		QuadTree(A, r+n/2, c+n/2, n/2);
		printf(")");
	}
}

int main() {
	int N, i, j, **A;
	scanf("%d", &N);
	A = (int **)malloc(sizeof(int *) * N);
	for(i = 0; i < N; i++) {
		A[i] = (int *)malloc(sizeof(int) * N);
		for(j = 0; j < N; j++)
			scanf("%1d", &A[i][j]);
	}

	QuadTree(A, 0, 0, N);
	printf("\n");

	for(i = 0; i < N; i++)
		free(A[i]);
	free(A);
	return 0;
}

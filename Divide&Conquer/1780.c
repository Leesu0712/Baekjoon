#include <stdio.h>
#include <stdlib.h>
#define NMAX 2187

void Papercnt(int **A, int r, int c, int n, int* cnt) {
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
		cnt[dot+1]++;
	else {
		for(i = r; i < r + n; i += n/3) {
			for(j = c; j < c + n; j += n/3) {
				Papercnt(A, i, j, n/3, cnt);
			}
		}
	}
}

int main() {
	int N, i, j, **A;
	int *cnt = (int *)malloc(sizeof(int) * 3);
	scanf("%d", &N);
	A = (int **)malloc(sizeof(int *) * N);
	for(i = 0; i < N; i++) {
		A[i] = (int *)malloc(sizeof(int) * N);
		for(j = 0; j < N; j++)
			scanf("%d", &A[i][j]);
	}

	Papercnt(A, 0, 0, N, cnt);
	printf("%d\n%d\n%d\n", cnt[0], cnt[1], cnt[2]);

	for(i = 0; i < N; i++)
		free(A[i]);
	free(A);
	return 0;
}

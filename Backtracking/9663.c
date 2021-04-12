#include <stdio.h>
#include <stdlib.h>

void backtracking(int row, int N, int* col, int* rdia, int* ldia, int* cnt) {
	int i;
	if(row == N) {
		*cnt = *cnt + 1;
		return;
	}
	for(i = 0; i < N; i++) {
		if(!col[i]) {
			if(!rdia[row - i + (N - 1)] && !ldia[row + i]) {
				col[i] = 1;
				rdia[row - i + (N - 1)] = 1;
				ldia[row + i] = 1;
				backtracking(row + 1, N, col, rdia, ldia, cnt);
				col[i] = 0;
				rdia[row - i + (N - 1)] = 0;
				ldia[row + i] = 0;
			}
		}
	}
	return;
}

int main() {
	int N, i;
	int *col, *rdia, *ldia, *cnt;
	scanf("%d", &N);
	cnt = (int *)malloc(sizeof(int));
	col = (int *)malloc(sizeof(int) * N);
	rdia = (int *)malloc(sizeof(int) * (2 * N - 1));
	ldia = (int *)malloc(sizeof(int) * (2 * N - 1));
	*cnt = 0;
	for(i = 0; i < N; i++)
		col[i] = 0;
	for(i = 0; i < 2 * N - 1; i++) {
		rdia[i] = 0;
		ldia[i] = 0;
	}

	backtracking(0, N, col, rdia, ldia, cnt);

	printf("%d\n", *cnt);

	free(cnt);
	free(col);
	free(rdia);
	free(ldia);

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#define MAX 900

int stat(int **arr, int *team, int N) {
	int i, j, sum = 0;
	for(i = 0; i < N / 2; i++) {
		for(j = 0; j < N / 2; j++) {
			if(i == j)
				continue;
			sum += arr[team[i]][team[j]];
		}
	}
	return sum;
}

void backtracking(int m, int k, int N, int **arr, int *cnt, int *start, int *link, int *ans) {
	int i, n = 0, statdiff;
	if(m == N / 2) {
		for(i = 0; i < N; i++) {
			if(!cnt[i]) {
				link[n] = i;
				n++;
			}
		}
		statdiff = abs(stat(arr, start, N) - stat(arr, link, N));
		if(statdiff < *ans)
			*ans = statdiff;
	}
	else {
		for(i = k; i < N; i++) {
			if(!cnt[i]) {
				cnt[i] = 1;
				start[m] = i;
				backtracking(m + 1, i + 1, N, arr, cnt, start, link, ans);
				cnt[i] = 0;
			}
		}
		return;
	}
}

int main() {
	int N, i, j;
	int *cnt, *start, *link, *ans;
	int **A;
	scanf("%d", &N);
	A = (int **)malloc(sizeof(int *) * N);
	A[0] = (int *)malloc(sizeof(int) * (N * N));
	cnt = (int *)malloc(sizeof(int) * N);
	start = (int *)malloc(sizeof(int) * N / 2);
	link = (int *)malloc(sizeof(int) * N / 2);
	ans = (int *)malloc(sizeof(int));
	for(i = 0; i < N; i++) {
		if(i)
			A[i] = A[i - 1] + N;
		for(j = 0; j < N; j++)
			scanf("%d", &A[i][j]);
		cnt[i] = 0;
	}
	*ans = MAX;
	printf("A[0] %p\ncnt %p\nstart %p\nlink %p\nans %p\n", A[0], cnt, start, link, ans);

	backtracking(0, 0, N, A, cnt, start, link, ans);

	printf("%d\n", *ans);

	free(A[0]);
	free(A);
	free(cnt);
	free(start);
	free(link);
	free(ans);
	return 0;
}

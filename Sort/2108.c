#include <stdio.h>
#include <stdlib.h>
#define MAX 4000

int static compare(const void* first, const void* second) {
	if(*(int*)first > *(int*)second)
		return 1;
	else if(*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}

int main() {
	int N, i, n, maxcnt = 0, mult = 0, mean, median, mode, range;
	double sum = 0, realmean;
	int *A;
	int cnt[MAX * 2 + 1] = { 0, };
	scanf("%d", &N);
	A = (int*)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++) {
		scanf("%d", &n);
		A[i] = n;
		cnt[n + MAX]++;
		sum += n;
	}
	realmean = sum / N;
	mean = realmean >= 0 ? (int)(realmean + 0.5) : (int)(realmean - 0.5);

	qsort(A, N, sizeof(int), compare);
	median = A[N / 2];
	range = A[N - 1] - A[0];

	for(i = 0; i < MAX * 2 + 1; i++) {
		if(cnt[i] > maxcnt)
			maxcnt = cnt[i];
	}
	for(i = 0; i < MAX * 2 + 1; i++) {
		if(cnt[i] == maxcnt) {
			if(mult) {
				mode = i - MAX;
				break;
			}
			else {
				mode = i - MAX;
				mult++;
			}
		}
	}

	printf("%d\n%d\n%d\n%d\n", mean, median, mode, range);
	free(A);
	return 0;
}

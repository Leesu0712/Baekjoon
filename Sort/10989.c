#include <stdio.h>
#define MAX 10001

int main() {
	int N, i, n, j, rep;
	int A[MAX] = { 0, };
	scanf("%d", &N);

	for(i = 0; i < N; i++) {
		scanf("%d", &n);
		A[n]++;
	}

	for(i = 1; i < MAX; i++)
		A[i] = A[i - 1] + A[i];

	for(i = 1; i < MAX; i++) {
		rep = A[i] - A[i - 1];
		for(j = 0; j < rep; j++)
			printf("%d\n", i);
	}

	return 0;
}

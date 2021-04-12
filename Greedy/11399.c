#include <stdio.h>
#define NMAX 1000

static int compare(const void *A, const void *B) {
	if(*(int *)A > *(int *)B)
		return 1;
	else if(*(int *)A < *(int *)B)
		return -1;
	else
		return 0;
}

int main() {
	int N, i, P[NMAX], SUM[NMAX], sum = 0;
	scanf("%d", &N);
	for(i = 0; i < N; i++)
		scanf("%d", &P[i]);

	qsort(P, N, sizeof(int), compare);

	SUM[0] = P[0];
	for(i = 1; i < N; i++)
		SUM[i] = SUM[i-1] + P[i];

	for(i = 0; i < N; i++)
		sum += SUM[i];

	printf("%d\n", sum);
	return 0;
}

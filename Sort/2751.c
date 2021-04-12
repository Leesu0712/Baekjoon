#include <stdio.h>
#include <stdlib.h>

int static compare(const void* first, const void* second) {
	if(*(int*)first > *(int*)second)
		return 1;
	else if(*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}

int main() {
	int N, i;
	int *A;
	scanf("%d", &N);
	A = (int*)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++)
		scanf("%d", &A[i]);

	qsort(A, N, sizeof(int), compare);

	for(i = 0; i < N; i++)
		printf("%d\n", A[i]);

	free(A);
	return 0;
}

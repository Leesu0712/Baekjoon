#include <stdio.h>
#include <stdlib.h>

static int compare(const void* first, const void* second) {
	if(*(int*)first < *(int*)second)
		return 1;
	else if(*(int*)first > *(int*)second)
		return -1;
	else
		return 0;
}

int main() {
	int N, n, i, cnt = 0;
	int A[10];
	scanf("%d", &N);

	n = N;
	for(i = 0; n > 0; i++) {
		A[i] = n % 10;
		n = n / 10;
		cnt++;
	}

	qsort(A, cnt, sizeof(int), compare);

	n = A[0];
	for(i = 1; i < cnt; i++) {
		n *= 10;
		n += A[i];
	}
	printf("%d\n", n);
	return 0;
}

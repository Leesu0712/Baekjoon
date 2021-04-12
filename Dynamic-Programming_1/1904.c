#include <stdio.h>
#include <stdlib.h>
#define DNUM 15746

int main() {
	int N, i;
	int *arr;
	scanf("%d", &N);
	arr = (int *)malloc(sizeof(int) * (N + 1));
	arr[1] = 1;
	arr[2] = 2;
	for(i = 3; i < N + 1; i++)
		arr[i] = (arr[i - 1] % DNUM + arr[i - 2] % DNUM) % DNUM;

	printf("%d\n", arr[N]);

	free(arr);
	return 0;
}

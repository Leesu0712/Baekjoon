#include <stdio.h>
#include <stdlib.h>

void backtracking(int m, int N, int M, int* num, int* out) {
	int i;
	if(m == M) {
		for(i = 0; i < M; i++)
			printf("%d ", out[i]);
		printf("\n");
		return;
	}
	for(i = 0; i < N; i++) {
		if(!num[i]) {
			num[i] = 1;
			out[m] = i + 1;
			backtracking(m + 1, N, M, num, out);
			num[i] = 0;
		}
	}
	return;
}

int main() {
	int N, M, i;
	int* num;
	int* out;
	scanf("%d %d", &N, &M);
	num = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++)
		num[i] = 0;
	out = (int *)malloc(sizeof(int) * M);

	backtracking(0, N, M, num, out);

	return 0;
}

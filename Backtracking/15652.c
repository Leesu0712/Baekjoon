#include <stdio.h>
#include <stdlib.h>

void backtracking(int m, int N, int M, int* out) {
	int i;
	if(m == M) {
		for(i = 0; i < M; i++)
			printf("%d ", out[i]);
		printf("\n");
		return;
	}
	for(i = 0; i < N; i++) {
		if(m && (out[m - 1] > i + 1))
			continue;
		out[m] = i + 1;
		backtracking(m + 1, N, M, out);
	}
	return;
}

int main() {
	int N, M, i;
	int *out;
	scanf("%d %d", &N, &M);
	out = (int *)malloc(sizeof(int) * M);

	backtracking(0, N, M, out);

	return 0;
}

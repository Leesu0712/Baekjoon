#include <stdio.h>
#include <stdlib.h>

int main() {
	int N, M, i, j, k, sum, ans = 0;
	int *C;
	scanf("%d %d", &N, &M);
	C = (int*)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++)
		scanf("%d", &C[i]);

	for(i = 0; i < N - 2; i++) {
		for(j = i + 1; j < N - 1; j++) {
			for(k = j + 1; k < N; k++) {
				sum = C[i] + C[j] + C[k];
				if((sum > ans) && (sum <= M))
					ans = sum;
			}
		}
	}
	printf("%d\n", ans);
	free(C);
	return 0;
}

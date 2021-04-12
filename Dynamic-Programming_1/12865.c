#include <stdio.h>
#include <stdlib.h>
#define NMAX 100
#define KMAX 100000
#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
	int N, K, i, j, W[NMAX + 1], V[NMAX + 1];
	int **dyn;
	scanf("%d %d", &N, &K);
	for(i = 1; i <= N; i++)
		scanf("%d %d", &W[i], &V[i]);

	dyn = (int **)malloc(sizeof(int *) * (K + 1));
	for(i = 0; i <= K; i++)
		dyn[i] = (int *)malloc(sizeof(int) * (N + 1));

	for(i = 0; i <= K; i++)
		dyn[i][0] = 0;
	for(j = 0; j <= N; j++)
		dyn[0][j] = 0;

	for(i = 1; i <= K; i++) {
		for(j = 1; j <= N; j++) {
			if(i < W[j])
				dyn[i][j] = dyn[i][j-1];
			else
				dyn[i][j] = max(dyn[i - W[j]][j-1] + V[j], dyn[i][j-1]);
		}
	}

	printf("%d\n", dyn[K][N]);

	for(i = 0; i <= K; i++)
		free(dyn[i]);
	free(dyn);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#define LIMIT 10000

int main() {
	int N, i, j, k, psum = 0, maxsum;
	int W[LIMIT];
	int **sum;
	scanf("%d", &N);
	for(i = 0; i < N; i++)
		scanf("%d", &W[i]);

	sum = (int**)malloc(sizeof(int*) * LIMIT);

	for(i = 0; i < LIMIT; i++) {
		sum[i] = (int*)malloc(sizeof(int) * 3);
	}

	for(i = 0; i < 3; i++)
		sum[i][i] = W[i];
	sum[0][1] = 0;
	sum[0][2] = 0;
	sum[1][0] = W[0] + W[1];
	sum[1][2] = 0;
	maxsum = sum[1][0];

	for(i = 2; i < N; i++) {
		for(j = 0; j < 3; j++) {
			if(i == j) continue;
				for(k = 0; k < 3; k++) {
					if(!j && !k)
						continue;
					else {
						if(sum[i-j-1][k] > psum)
							psum = sum[i-j-1][k];
					}
				}
				sum[i][j] = psum + W[i];
				if(sum[i][j] > maxsum)
					maxsum = sum[i][j];
				psum = 0;
		}
	}

	printf("%d\n", maxsum);

	for(i = 0; i < LIMIT; i++)
		free(sum[i]);
	free(sum);
	return 0;
}

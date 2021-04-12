#include <stdio.h>
#define LIMIT 500
#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
	int N, i, j, ans = 0;
	int T[LIMIT+1][LIMIT+1], sum[LIMIT][LIMIT];
	scanf("%d", &N);

	for(j = 1; j < N + 1; j++)
		for(i = 0; i < j; i++)
			scanf("%d", &T[j - 1][i]);

	sum[0][0] = T[0][0];
	sum[0][1] = T[0][0];
	for(j = 1; j < N; j++) {
		for(i = 0; i < j + 2; i++) {
			if(!i)
				sum[j][i] = T[j][0] + sum[j - 1][0];
			else if (i == j + 1)
				sum[j][i] = T[j][j] + sum[j - 1][j];
			else
				sum[j][i] = max(T[j][i - 1] + sum[j - 1][i - 1], T[j][i] + sum[j - 1][i]);
		}
	}

	for(i = 0; i < N; i++)
		if(sum[N - 1][i] > ans)
			ans = sum[N - 1][i];

	printf("%d\n", ans);
	return 0;
}

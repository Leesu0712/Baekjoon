#include <stdio.h>
#include <stdlib.h>
#define LIMIT 1000
#define min(a, b) (a < b ? a : b)

int main() {
	int N, i;
	int H[LIMIT][3], cost[LIMIT][3];
	scanf("%d", &N);
	for(i = 0; i < N; i++) {
		scanf("%d %d %d", &H[i][0], &H[i][1], &H[i][2]);
	}

	cost[0][0] = min(H[0][1], H[0][2]);
	cost[0][1] = min(H[0][0], H[0][2]);
	cost[0][2] = min(H[0][0], H[0][1]);
	for(i = 1; i < N; i++) {
		cost[i][0] = min(H[i][1] + cost[i - 1][1], H[i][2] + cost[i - 1][2]);
		cost[i][1] = min(H[i][0] + cost[i - 1][0], H[i][2] + cost[i - 1][2]);
		cost[i][2] = min(H[i][0] + cost[i - 1][0], H[i][1] + cost[i - 1][1]);
	}

	printf("%d\n", min(min(cost[N - 1][0], cost[N - 1][1]), cost[N - 1][2]));

	return 0;
}

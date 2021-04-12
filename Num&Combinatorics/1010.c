#include <stdio.h>
#define MAX 30

int main() {
	int T, i, j, k, N, M, Ptr[MAX][MAX];
	scanf("%d", &T);
	for(k = 0; k < T; k++) {
		scanf("%d %d", &N, &M);
		for(i = 0; i <= M; i++) {
			for(j = 0; j <= i; j++) {
				if((!j) || (j == i))
					Ptr[i][j] = 1;
				else
					Ptr[i][j] = Ptr[i-1][j-1] + Ptr[i-1][j];
			}
		}
		printf("%d\n", Ptr[M][N]);
	}
	return 0;
}

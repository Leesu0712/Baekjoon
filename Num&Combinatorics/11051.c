#include <stdio.h>
#define NMAX 1000
#define MOD 10007

int main() {
	int N, K, i, j, Ptr[NMAX+1][NMAX+1];
	scanf("%d %d", &N, &K);
	for(i = 0; i <= N; i++) {
		for(j = 0; j <= i; j++) {
			if((!j) || (j == i))
				Ptr[i][j] = 1;
			else
				Ptr[i][j] = (Ptr[i-1][j-1] % MOD + Ptr[i-1][j] % MOD) % MOD;
		}
	}
	printf("%d\n", Ptr[N][K]);
	return 0;
}

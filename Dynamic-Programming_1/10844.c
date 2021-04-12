#include <stdio.h>
#define LIMIT 100
#define MOD 1000000000

int main() {
	int N, n, i, sum = 0;
	int cnt[LIMIT][10];
	scanf("%d", &N);

	cnt[0][0] = 0;
	for(i = 1; i < 10; i++)
		cnt[0][i] = 1;

	for(n = 1; n < N; n++) {
		for(i = 0; i < 10; i++) {
			if(i == 0)
				cnt[n][i] = cnt[n-1][i+1] % MOD;
			else if(i == 9)
				cnt[n][i] = cnt[n-1][i-1] % MOD;
			else
				cnt[n][i] = (cnt[n-1][i-1] + cnt[n-1][i+1]) % MOD;
		}
	}

	for(i = 0; i < 10; i++)
		sum = (sum + cnt[N-1][i]) % MOD;

	printf("%d\n", sum);
	return 0;
}

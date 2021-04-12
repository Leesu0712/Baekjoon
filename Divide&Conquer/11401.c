#include <stdio.h>
#define MOD 1000000007

long long func(long long A, long long B, long long C) {
	if(B == 1)
		return A % C;
	else if(B % 2)
		return func(A, 1, C) * func(A, B-1, C) % C;
	else
		return func(A, B/2, C) * func(A, B/2, C) % C;
}

int main() {
	int N, K, i;
	long long mod1, mod2;
	scanf("%d %d", &N, &K);

	mod1 = 1;
	for(i = 2; i <= N; i++)
		mod1 = ((mod1 % MOD) * (i % MOD)) % MOD;
	printf("mod1 = %lld\n", mod1);
	mod2 = 1;
	for(i = 2; i <= K; i++)
		mod2 = ((mod2 % MOD) * (i % MOD)) % MOD;
	printf("mod2 = %lld\n", mod2);
	for(i = 2; i <= N - K; i++)
		mod2 = ((mod2 % MOD) * (i % MOD)) % MOD;
	printf("mod2 = %lld\n", mod2);
	mod2 = func(mod2, MOD - 2, MOD);
	printf("mod2 = %lld\n", mod2);

	printf("%lld\n", ((mod1 % MOD) * (mod2 % MOD)) % MOD);

	return 0;
}

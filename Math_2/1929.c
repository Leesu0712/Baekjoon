#include <stdio.h>

void EratosPrime(int N, int* PrimeArr) {
	int i, j;

	for(i = 2; i <= N; i++)
		PrimeArr[i] = 1;

	for(i = 2; i * i <= N; i++) {
		if(PrimeArr[i]) {
			for(j = i * i; j <= N; j += i)
				PrimeArr[j] = 0;
		}
	}
}

int main() {
	int M, N, i;
	scanf("%d %d", &M, &N);
	int PrimeArr[N + 1];
	EratosPrime(N, PrimeArr);

	for(i = M; i <= N; i++) {
		if(PrimeArr[i])
			printf("%d\n", i);
	}
	return 0;
}

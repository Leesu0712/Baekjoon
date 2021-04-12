#include <stdio.h>

void prime(int N, int* PrimeArr) {
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
	int N, i, n;
	scanf("%d", &N);
	int PrimeArr[N + 1];
	prime(N, PrimeArr);

	if(N == 1)
		return 0;
	else {
		n = N;
		for(i = 2; i <= N; i++) {
			if(PrimeArr[i]) {
				while(!(n % i)) {
					printf("%d\n", i);
					n = n / i;
				}
			}
		}
	}
	return 0;
}

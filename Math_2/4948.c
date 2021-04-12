#include <stdio.h>
#include <stdlib.h>

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
	int i, cnt, n = 1;
	int* PrimeArr;
	while(1) {
		scanf("%d", &n);
		if(!n)
			return 0;
		PrimeArr = (int *)malloc(sizeof(int) * (n * 2 + 1));
		EratosPrime(n * 2, PrimeArr);
		cnt = 0;
		for(i = n + 1; i <= 2 * n; i++) {
			if(PrimeArr[i])
				cnt++;
		}
		printf("%d\n", cnt);
		free(PrimeArr);
	}
	return 0;
}

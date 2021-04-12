#include <stdio.h>
#include <stdlib.h>

void EratosPrime(int N, int* Arr) {
	int i, j;

	for(i = 2; i <= N; i++)
		Arr[i] = 1;

	for(i = 2; i * i <= N; i++) {
		if(Arr[i]) {
			for(j = i * i; j <= N; j += i)
				Arr[j] = 0;
		}
	}
}

int main() {
	int T, n, i, j, prev;
	int* PrimeArr;
	scanf("%d", &T);
	
	for(i = 0; i < T; i++) {
		scanf("%d", &n);
		PrimeArr = (int*)malloc(sizeof(int) * (n + 1));
		EratosPrime(n, PrimeArr);
		prev = 0;
		for(j = 2; j < n; j++) {
			if(j == prev)
				break;
			else if(PrimeArr[j]) {
				if(PrimeArr[n - j]) {
					prev = n - j;
					if(j == prev)
						break;
				}
			}
		}
		printf("%d %d\n", n - prev, prev);
		free(PrimeArr);
	}
	return 0;
}

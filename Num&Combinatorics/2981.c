#include <stdio.h>
#define NMAX 100

int gcd(int a, int b) {
	int c;
	while(b) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
	int N, i, A[NMAX], diff, pgcd;
	scanf("%d", &N);
	for(i = 0; i < N; i++)
		scanf("%d", &A[i]);

	pgcd = A[0] > A[1] ? A[0]-A[1] : A[1]-A[0];
	for(i = 1; i < N - 1; i++) {
		diff = A[i] > A[i+1] ? A[i]-A[i+1] : A[i+1]-A[i];
		pgcd = gcd(pgcd, diff);
	}
	
	if(pgcd % 2) {
		for(i = 2; i <= pgcd; i++)
			if(!(pgcd % i))
				printf("%d ", i);
	}
	else {
		for(i = 2; i <= pgcd/2; i++)
			if(!(pgcd % i))
				printf("%d ", i);
		printf("%d", pgcd);
	}
	printf("\n");

	return 0;
}

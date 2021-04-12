#include <stdio.h>

int factorial(int n) {
	if(!n)
		return 1;
	else
		return factorial(n-1) * n;
}

int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	printf("%d\n", factorial(N) / (factorial(K) * factorial(N-K)));
	return 0;
}

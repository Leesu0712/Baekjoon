#include <stdio.h>

int Fibonacci(int n) {
	if(!n)
		return 0;
	else if(n == 1)
		return 1;
	else
		return Fibonacci(n - 2) + Fibonacci(n - 1);
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", Fibonacci(n));
	return 0;
}

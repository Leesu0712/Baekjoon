#include <stdio.h>

long long func(long long A, long long B, long long C) {
	if(B == 1)
		return A % C;
	else if(B % 2)
		return func(A, 1, C) * func(A, B-1, C) % C;
	else
		return func(A, B/2, C) * func(A, B/2, C) % C;
}

int main() {
	long long A, B, C;
	scanf("%lld %lld %lld", &A, &B, &C);

	printf("%lld\n", func(A, B, C));

	return 0;
}

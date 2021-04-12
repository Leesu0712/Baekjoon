#include <stdio.h>

int main() {
	char A[4], B[4];
	int i, a, b;
	scanf("%s", A);
	scanf("%s", B);

	a = (A[0] - 48) + (A[1] - 48) * 10 + (A[2] - 48) * 100;
	b = (B[0] - 48) + (B[1] - 48) * 10 + (B[2] - 48) * 100;

	if(a > b)
		printf("%d\n", a);
	else
		printf("%d\n", b);

	return 0;
}

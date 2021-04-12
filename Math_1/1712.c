#include <stdio.h>

int main() {
	int A, B, C, i;
	scanf("%d %d %d", &A, &B, &C);

	if(C <= B)
		printf("%d\n", -1);
	else {
		i = A / (C - B);
		printf("%d\n", i + 1);
	}
	return 0;
}

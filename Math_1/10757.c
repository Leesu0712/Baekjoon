#include <stdio.h>

int main() {
	char A[10001], B[10001], SUM[10002];
	int i, a, b, large, gap, pa, pb, carry;
	scanf("%s %s", A, B);

	for(i = 0; A[i] != '\0'; i++)
		;
	a = i;
	for(i = 0; B[i] != '\0'; i++)
		;
	b = i;

	carry = 0;
	if(a > b) {
		gap = a - b;
		for(i = a - 1; i >= 0; i--) {
			pa = A[i] - 48;
			if((i - gap) < 0)
				pb = 0;
			else
				pb = B[i - gap] - 48;
			SUM[i + 1] = (pa + pb + carry) % 10;
			carry = (pa + pb + carry) / 10;
		}
		SUM[0] = carry;
	}
	else {
		gap = b - a;
		for(i = b - 1; i >= 0; i--) {
			pb = B[i] - 48;
			if((i - gap) < 0)
				pa = 0;
			else
				pa = A[i - gap] - 48;
			SUM[i + 1] = (pa + pb + carry) % 10;
			carry = (pa + pb + carry) / 10;
		}
		SUM[0] = carry;
	}
	large = a > b ? a : b;
	for(i = 0; i < (large + 1); i++) {
		if((i != 0) || (SUM[0]))
			printf("%d", SUM[i]);
	}
	printf("\n");

	return 0;
}

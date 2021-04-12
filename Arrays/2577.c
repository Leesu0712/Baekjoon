#include <stdio.h>

int main() {
	int A, B, C, num, i;
	int cnt[10] = { 0, };

	scanf("%d\n%d\n%d", &A, &B, &C);

	num = A * B * C;
	for(i = 0; num > 0; i++) {
		cnt[num % 10]++;
		num = num / 10;
	}

	for(i = 0; i < 10; i++) {
		printf("%d\n", cnt[i]);
	}

	return 0;
}


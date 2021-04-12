#include <stdio.h>

int main() {
	int A[10];
	int cnt[42] = { 0, };
	int i, sum;

	for(i = 0; i < 10; i++)
		scanf("%d", &A[i]);

	sum = 0;
	for(i = 0; i < 10; i++) {
		if(!cnt[A[i] % 42]) {
			cnt[A[i] % 42] = 1;
			sum++;
		}
	}
	printf("%d\n", sum);

	return 0;
}

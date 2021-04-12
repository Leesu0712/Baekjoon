#include <stdio.h>

int main() {
	int A[9];
	int i = 0;
	int max, num;

	while(scanf("%d", &A[i]) != EOF) {
		i++;
	}

	max = A[0];
	num = 1;
	for(i = 1; i < 9; i++) {
		if(A[i] > max) {
			max = A[i];
			num = i + 1;
		}
	}
	printf("%d\n%d\n", max, num);

	return 0;
}

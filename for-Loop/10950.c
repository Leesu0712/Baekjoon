#include <stdio.h>
#include <stdlib.h>

int main() {
	int T, i, A, B;
	scanf("%d", &T);
    int *sum = malloc(sizeof(int) * T);

	for(i = 0; i < T; i++) {
		scanf("%d %d", &A, &B);
		sum[i] = A+B;
	}

	for(i = 0; i < T; i++)
		printf("%d\n", sum[i]);

	free(sum);

	return 0;
}

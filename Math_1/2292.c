#include <stdio.h>

int main() {
	int N, i;
	int limit = 1;
	scanf("%d", &N);

	for(i = 1; limit < N; i++) {
		limit += 6 * i;
	}
	printf("%d\n", i);
	return 0;
}

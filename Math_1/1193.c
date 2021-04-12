#include <stdio.h>

int main() {
	int N, i, gap;
	int sum = 0;
	scanf("%d", &N);

	for(i = 0; sum < N; i++) {
		sum += (i + 1);
	}
	gap = i - (sum - N);

	if(i % 2)
		printf("%d/%d\n", i - (gap - 1), 1 + (gap - 1));
	else
		printf("%d/%d\n", 1 + (gap - 1), i - (gap - 1));

	return 0;
}

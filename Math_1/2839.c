#include <stdio.h>

int main() {
	int N, k, i;
	int ans = -1;
	scanf("%d", &N);

	k = N / 5;
	for(i = k; i >= 0; i--) {
		if((N - i * 5) % 3)
			continue;
		else {
			ans = i + (N - i * 5) / 3;
			break;
		}
	}
	printf("%d\n", ans);
	
	return 0;
}

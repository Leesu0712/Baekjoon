#include <stdio.h>

int main() {
	int N, i, k, sum = 0;
	scanf("%d", &N);

	for(i = 1; i < N; i++) {
		k = i;
		sum = i;
		while(1) {
			sum += k % 10;
			k = k / 10;
			if(!k)
				break;
		}
		if(sum == N) { 
			printf("%d\n", i);
			return 0;
		}
	}
	printf("%d\n", 0);
	return 0;
}

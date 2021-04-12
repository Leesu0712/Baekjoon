#include <stdio.h>

int main() {
	int N, i, n, min, max;
	scanf("%d", &N);
	for(i = 0; i < N; i++) {
		scanf("%d", &n);
		if(!i) {
			min = n;
			max = n;
		}
		else {
			if(n < min)
				min = n;
			else if(n > max)
				max = n;
		}
	}
	printf("%d\n", min * max);
	return 0;
}

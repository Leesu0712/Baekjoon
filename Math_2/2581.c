#include <stdio.h>

int prime(int n) {
	int i;
	for(i = 2; i < n; i++) {
		if(!(n % i))
			break;
	}
	if(i == n)
		return 1;
	else
		return 0;
}

int main() {
	int M, N, i, j, min;
	int cnt = 0, sum = 0;
	scanf("%d\n%d", &M, &N);

	for(i = M; i <= N; i++) {
		if(prime(i)) {
			cnt++;
			if(cnt == 1)
				min = i;
			sum += i;
		}
	}
	if(!cnt)
		printf("%d\n", -1);
	else
		printf("%d\n%d\n", sum, min);

	return 0;
}

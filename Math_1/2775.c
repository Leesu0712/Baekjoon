#include <stdio.h>

int cal(int k, int n) {
	int i;
	int sum = 0;

	if(k == 1) {
		for(i = 1; i <= n; i++)
			sum += i;
		return sum;
	}
	else {
		for(i = 1; i <= n; i++)
			sum += cal(k - 1, i);
		return sum;
	}
}

int main() {
	int T, k, n, i;
	scanf("%d", &T);

	for(i = 0; i < T; i++) {
		scanf("%d\n%d", &k, &n);
		printf("%d\n", cal(k, n));
	}
	return 0;
}

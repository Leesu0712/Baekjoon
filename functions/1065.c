#include <stdio.h>

int len(int n) {
	int i, c;

	c = n;
	for(i = 0; c > 0; i++) {
		c = c / 10;
	}

	return i;
}

int check(int n, int len) {
	int i, c, lowdiff, highdiff;

	lowdiff = ((n / 10) % 10) - (n % 10);
	c = n / 10;
	for(i = 1; i < (len - 1); i++) {
		highdiff = ((c / 10) % 10) - (c % 10);
		if(lowdiff != highdiff)
			return 0;
		c = c / 10;
	}
	return 1;
}

int main() {
	int N, i;
	int cnt = 0;
	scanf("%d", &N);

	for(i = 1; i <= N; i++) {
		if(check(i, len(i)))
			cnt++;
	}
	printf("%d\n", cnt);

	return 0;
}


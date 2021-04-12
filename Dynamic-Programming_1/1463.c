#include <stdio.h>
#define LIMIT 1000000
#define min(a, b) ((a) < (b) ? (a) : (b))

int main() {
	int N, i, cnt[LIMIT];
	scanf("%d", &N);

	cnt[0] = 0;
	for(i = 2; i < N + 1; i++) {
		if(!(i % 2) && !(i % 3))
			cnt[i-1] = min(min(cnt[i/2-1], cnt[i/3-1]), cnt[i-2]) + 1;
		else if(!(i % 3))
			cnt[i-1] = min(cnt[i/3-1], cnt[i-2]) + 1;
		else if(!(i % 2))
			cnt[i-1] = min(cnt[i/2-1], cnt[i-2]) + 1;
		else
			cnt[i-1] = cnt[i-2] + 1;
	}

	printf("%d\n", cnt[N - 1]);

	return 0;
}

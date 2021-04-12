#include <stdio.h>
#define LIMIT 1000

int main() {
	int N, i, j, tmp, maxcnt, cnt[LIMIT], A[LIMIT];
	scanf("%d", &N);
	for(i = 0; i < N; i++)
		scanf("%d", &A[i]);

	cnt[0] = 1;
	for(i = 1; i < N; i++) {
		maxcnt = 1;
		for(j = 0; j < i; j++) {
			if(A[j] < A[i]) {
				tmp = cnt[j] + 1;
				if(tmp > maxcnt)
					maxcnt = tmp;
			}
		}
		cnt[i] = maxcnt;
	}

	for(i = 0; i < N; i++)
		if(cnt[i] > maxcnt)
			maxcnt = cnt[i];

	printf("%d\n", maxcnt);

	return 0;
}

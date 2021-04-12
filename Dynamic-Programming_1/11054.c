#include <stdio.h>
#define LIMIT 1000

int main() {
	int N, i, j, tmp, maxcnt, as[LIMIT], des[LIMIT], A[LIMIT];
	scanf("%d", &N);
	for(i = 0; i < N; i++)
		scanf("%d", &A[i]);

	as[0] = 1;
	for(i = 1; i < N; i++) {
		maxcnt = 1;
		for(j = 0; j < i; j++) {
			if(A[j] < A[i]) {
				if(as[j] + 1 > maxcnt)
					maxcnt = as[j] + 1;
			}
		}
		as[i] = maxcnt;
	}

	des[0] = 1;
	for(i = N - 1; i >= 0; i--) {
		maxcnt = 1;
		for(j = N - 1; j > i; j--) {
			if(A[j] < A[i]) {
				if(des[j] + 1 > maxcnt)
					maxcnt = des[j] + 1;
			}
		}
		des[i] = maxcnt;
	}

	for(i = 0; i < N; i++)
		if((as[i] + des[i] - 1) > maxcnt)
			maxcnt = as[i] + des[i] - 1;

	printf("%d\n", maxcnt);

	return 0;
}

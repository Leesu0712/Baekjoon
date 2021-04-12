#include <stdio.h>
#define LIMIT 501

struct wire {
	int A;
	int B;
};

int static compare(const void* a, const void* b) {
	int* pta = (int*)a;
	int* ptb = (int*)b;
	if(*pta > *ptb)
		return 1;
	else if(*pta < *ptb)
		return -1;
	else
		return 0;
}

int main() {
	int N, i, j, maxcnt, as[LIMIT];
	struct wire W[LIMIT];
	scanf("%d", &N);
	for(i = 0; i < N; i++)
		scanf("%d %d", &W[i].A, &W[i].B);

	qsort(W, N, sizeof(W[0]), compare);

	as[0] = 1;
	for(i = 1; i < N; i++) {
		maxcnt = 1;
		for(j = 0; j < i; j++) {
			if(W[j].B < W[i].B)
				if(as[j] + 1 > maxcnt)
					maxcnt = as[j] + 1;
		}
		as[i] = maxcnt;
	}
	
	for(i = 0; i < N; i++)
		if(as[i] > maxcnt)
			maxcnt = as[i];

	printf("%d\n", N - maxcnt);
	return 0;
}

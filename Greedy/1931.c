#include <stdio.h>
#define NMAX 100000

struct meeting {
	int st;
	int et;
};

static int compare(const void *A, const void *B) {
	struct meeting *ptA = (struct meeting *)A;
	struct meeting *ptB = (struct meeting *)B;
	if(ptA->et > ptB->et)
		return 1;
	else if(ptA->et < ptB->et)
		return -1;
	else {
		if(ptA->st > ptB->st)
			return 1;
		else if(ptA->st < ptB->st)
			return -1;
		else
			return 0;
	}
}

int main() {
	int N, i, start, cnt = 0;
	struct meeting M[NMAX];
	scanf("%d", &N);
	for(i = 0; i < N; i++)
		scanf("%d %d", &M[i].st, &M[i].et);

	qsort(M, N, sizeof(M[0]), compare);

	start = 0;
	for(i = 0; i < N; i++) {
		if(M[i].st >= start) {
			start = M[i].et;
			cnt++;
			continue;
		}
	}

	printf("%d\n", cnt);

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxlen 52

struct word {
	char s[maxlen];
	int n;
};

static int compare(const void* A, const void *B) {
	struct word* ptA = (struct word*)A;
	struct word* ptB = (struct word*)B;
	int i;

	if(ptA->n > ptB->n)
		return 1;
	else if(ptA->n < ptB->n)
		return -1;
	else {
		for(i = 0; i < ptA->n; i++) {
			if(ptA->s[i] > ptB->s[i])
				return 1;
			else if(ptA->s[i] < ptB->s[i])
				return -1;
			else
				continue;
		}
		return 0;
	}
}

int main() {
	int N, i, j;
	struct word* A;
	scanf("%d", &N);
	A = malloc(sizeof(struct word) * N);
	for(i = 0; i < N; i++) {
		scanf("%s", &A[i].s[0]);
		for(j = 0; A[i].s[j] != '\0'; j++)
			;
		A[i].n = j;
	}

	qsort(A, N, sizeof(A[0]), compare);

	for(i = 0; i < N; i++) {
		if(i && !strcmp(A[i - 1].s, A[i].s))
			continue;
		printf("%s\n", A[i].s);
	}
	free(A);
	return 0;
}

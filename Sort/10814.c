#include <stdio.h>
#include <stdlib.h>
#define maxlen 101

struct member {
	int age;
	char name[maxlen];
	int join;
};

static int compare(const void* A, const void* B) {
	struct member* ptA = (struct member*)A;
	struct member* ptB = (struct member*)B;

	if(ptA->age > ptB->age)
		return 1;
	else if(ptA->age < ptB->age)
		return -1;
	else {
		if(ptA->join > ptB->join)
			return 1;
		else if(ptA->join < ptB->join)
			return -1;
		else
			return 0;
	}
}

int main() {
	int N, i;
	struct member* A;
	scanf("%d", &N);
	A = malloc(sizeof(struct member) * N);
	for(i = 0; i < N; i++) {
		scanf("%d %s", &A[i].age, &A[i].name[0]);
		A[i].join = i;
	}

	qsort(A, N, sizeof(A[0]), compare);

	for(i = 0; i < N; i++)
		printf("%d %s\n", A[i].age, A[i].name);

	free(A);
	return 0;
}

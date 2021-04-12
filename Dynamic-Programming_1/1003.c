#include <stdio.h>
#include <stdlib.h>

struct cnt {
	int zero;
	int one;
};

void fibcnt(int n, struct cnt* arr) {
	if(n == 0)
		arr[0].zero = 1;
	else if(n == 1)
		arr[1].one = 1;
	else {
		if(!arr[n - 2].zero && !arr[n - 2].one) {
			fibcnt(n - 2, arr);
			fibcnt(n - 1, arr);
		}
		else if(!arr[n - 1].zero && !arr[n - 1].one)
			fibcnt(n - 1, arr);
		arr[n].zero = arr[n - 1].zero + arr[n - 2].zero;
		arr[n].one = arr[n - 1].one + arr[n - 2].one;
	}
}

int main() {
	int T, i, j, N;
	struct cnt* arr;
	scanf("%d", &T);
	for(i = 0; i < T; i++) {
		scanf("%d", &N);
		arr = (struct cnt*)malloc(sizeof(struct cnt) * (N + 1));
		for(j = 0; j < N + 1; j++) {
			arr[j].zero = 0;
			arr[j].one = 0;
		}
		fibcnt(N, arr);
		printf("%d %d\n", arr[N].zero, arr[N].one);
		free(arr);
	}
	return 0;
}

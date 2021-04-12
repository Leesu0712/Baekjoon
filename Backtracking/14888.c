#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000000
#define MIN -1000000000

struct answer {
	int max;
	int min;
};

int operator(int a, int b, int op) {
	if(!op)
		return a + b;
	else if(op == 1)
		return a - b;
	else if(op == 2)
		return a * b;
	else
		return a >= 0 ? a / b : ((-1 * a) / b) * -1;
}

void backtracking(int m, int N, int* num, int* op, int* opcnt, int* order, struct answer* ans) {
	int i, pans;
	if(m == N - 1) {
		pans = num[0];
		for(i = 1; i < N; i++)
			pans = operator(pans, num[i], order[i - 1]);
		if(pans > ans->max)
			ans->max = pans;
		if(pans < ans->min)
			ans->min = pans;
		return;
	}
	for(i = 0; i < 4; i++) {
		if(opcnt[i] < op[i]) {
			opcnt[i]++;
			order[m] = i;
			backtracking(m + 1, N, num, op, opcnt, order, ans);
			opcnt[i]--;
		}
	}
	return;
}

int main() {
	int N, i;
	int op[4], opcnt[4] = { 0, };
	int *num, *order;
	struct answer *ans;
	scanf("%d", &N);
	num = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++)
		scanf("%d", &num[i]);
	for(i = 0; i < 4; i++)
		scanf("%d", &op[i]);
	order = (int *)malloc(sizeof(int) * (N - 1));
	ans = (struct answer *)malloc(sizeof(struct answer));
	ans->max = MIN;
	ans->min = MAX;

	backtracking(0, N, num, op, opcnt, order, ans);
	printf("%d\n%d\n", ans->max, ans->min);

	free(num);
	free(order);
	free(ans);

	return 0;
}

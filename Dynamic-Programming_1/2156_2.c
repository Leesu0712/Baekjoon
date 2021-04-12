#include <stdio.h>
#define LIMIT 10000
#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
	int n, i, W[LIMIT], q[LIMIT + 1];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &W[i]);

	q[0] = 0;
	q[1] = W[0];
	q[2] = W[0] + W[1];
	for(i = 3; i <= n; i++)
		q[i] = max(max(q[i-3] + W[i-2] + W[i-1], q[i-2] + W[i-1]), q[i-1]);

	printf("%d\n", q[n]);

	return 0;
}

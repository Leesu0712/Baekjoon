#include <stdio.h>
#define LIMIT 100000
#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
	int n, i, psum, ans, A[LIMIT], S[LIMIT+1];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &A[i]);

	psum = A[0];
	ans = A[0];
	for(i = 1; i < n; i++) {
		psum = max(psum + A[i], A[i]);
		if(psum > ans)
			ans = psum;
	}

	printf("%d\n", ans);
	return 0;
}

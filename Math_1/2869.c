#include <stdio.h>

int main() {
	int A, B, V, ans;
	scanf("%d %d %d", &A, &B, &V);

	if((V - A) % (A - B))
		ans = (V - A) / (A - B) + 2;
	else
		ans = (V - A) / (A - B) + 1;

	printf("%d\n", ans);

	return 0;
}

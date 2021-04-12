#include <stdio.h>

int main() {
	int N, old, new;
	int cycle = 0;
	scanf("%d", &N);

	old = N;
	new = 100;
	while(N != new) {
		new = (old % 10) * 10 + ((old / 10) + (old % 10)) % 10;
		old = new;
		cycle++;
	}
	printf("%d\n", cycle);
	
	return 0;
}

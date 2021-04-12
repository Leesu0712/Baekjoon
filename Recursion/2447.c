#include <stdio.h>

void printline(int N, int x) {
	int i, pred;
	pred = N / 3;

	if(N == 1)
		printf("*");
	else if((x < pred) || (x >= pred * 2)) {
		for(i = 0; i < 3; i++)
			printline(pred, (x % pred));
	}
	else {
		printline(pred, (x % pred));
		for(i = 0; i < pred; i++)
			printf(" ");
		printline(pred, (x % pred));
	}
}


int main() {
	int N, i;
	scanf("%d", &N);
	
	for(i = 0; i < N; i++) {
		printline(N, i);
		printf("\n");
	}

	return 0;
}

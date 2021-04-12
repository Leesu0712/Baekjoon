#include <stdio.h>

void moveprint(int N, int dep, int dest) {
	int via;
	switch(dep + dest) {
		case 3 : via = 3;
				 break;
		case 4 : via = 2;
				 break;
		case 5 : via = 1;
				 break;
	}

	if(N == 1)
		printf("%d %d\n", dep, dest);
	else {
		moveprint(N - 1, dep, via);
		moveprint(1, dep, dest);
		moveprint(N - 1, via, dest);
	}
}


int main() {
	int N, i, k = 1;
	scanf("%d", &N);

	for(i = 1; i < N; i++)
		k = k * 2 + 1;

	printf("%d\n", k);
	moveprint(N, 1, 3);

	return 0;
}

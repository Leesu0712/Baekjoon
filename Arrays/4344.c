#include <stdio.h>
#include <stdlib.h>

int main() {
	int C, N, i, j, aver;
	int* score;
	int sum = 0;
	int winner = 0;

	scanf("%d", &C);
    for(i = 0; i < C; i++) {
		scanf("%d", &N);
		score = malloc(sizeof(int) * N);
		for(j = 0; j < N; j++) {
			scanf("%d", &score[j]);
			sum += score[j];
		}
		aver = sum / N;
		for(j = 0; j < N; j++) {
			if(score[j] > aver)
				winner++;
		}
		printf("%.3lf%%\n", (double)(winner)/N*100);
		winner = 0;
		sum = 0;
		free(score);
	}
	return 0;
}


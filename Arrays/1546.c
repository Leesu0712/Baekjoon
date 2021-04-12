#include <stdio.h>
#include <stdlib.h>

int main() {
	int N, i;
	double aver;
	int max = 0;
	double sum = 0;
	scanf("%4d", &N);
	int *score = malloc(sizeof(int) * N);
	for(i = 0; i < N; i++) {
		scanf("%3d", &score[i]);
		if(score[i] > max)
			max = score[i];
		sum += score[i];
	}

	aver = (sum / max * 100) / N;
	printf("%lf\n", aver);

	free(score);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main() {
	int N, i, j;
	int score = 0;
	int sum = 0;
	char buf[80];
	int* total;

	scanf("%d", &N);
	total = malloc(sizeof(int) * N);

	for(i = 0; i < N; i++) {
		scanf("%s", buf);
		for(j = 0; buf[j] != '\0'; j++) {
			if(buf[j] == 'O')
				score++;
			else if(buf[j] == 'X')
				score = 0;
			sum += score;
		}
		total[i] = sum;
		score = 0;
		sum = 0;
	}

	for(i = 0; i < N; i++) {
		printf("%d\n", total[i]);
	}

	free(total);
	return 0;
}

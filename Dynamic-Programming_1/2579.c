#include <stdio.h>
#define LIMIT 300
#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
	int N, i;
	int S[LIMIT];
	int score[LIMIT][2];
	scanf("%d", &N);
	for(i = 0; i < N; i++)
		scanf("%d", &S[i]);

	score[0][0] = 0;
	score[0][1] = -1;
	score[1][0] = S[0];
	score[1][1] = 0;
	for(i = 2; i < N; i++) {
		if(i != N - 2)
			score[i][0] = score[i-1][1] + S[i-1];
		score[i][1] = max(score[i-2][0], score[i-2][1]) + S[i-2];
	}

	printf("%d\n", max(score[N-1][0], score[N-1][1]) + S[N-1]);

	return 0;
}

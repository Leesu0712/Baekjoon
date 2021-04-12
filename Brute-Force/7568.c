#include <stdio.h>
#include <stdlib.h>

struct body {
	int w;
	int h;
	int rank;
};

int main() {
	int N, i, j, cnt = 0;
	struct body *std;
	scanf("%d", &N);
	std = malloc(sizeof(struct body) * N);
	for(i = 0; i < N; i++)
		scanf("%d %d", &std[i].w, &std[i].h);

	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			if(i == j)
				continue;
			if((std[i].w < std[j].w) && (std[i].h < std[j].h))
				cnt++;
		}
		std[i].rank = cnt + 1;
		cnt = 0;
	}
	
	for(i = 0; i < N; i++)
		printf("%d ", std[i].rank);
	printf("\n");

	free(std);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct pos {
	int x;
	int y;
};

static int compare(const void* A, const void* B) {
	struct pos* ptA = (struct pos*)A;
	struct pos* ptB = (struct pos*)B;

	if(ptA->y > ptB->y)
		return 1;
	else if(ptA->y < ptB->y)
		return -1;
	else {
		if(ptA->x > ptB->x)
			return 1;
		else if(ptA->x < ptB->x)
			return -1;
		else
			return 0;
	}
}

int main() {
	int N, i, j;
	struct pos* dot;
	scanf("%d", &N);
	dot = (struct pos*)malloc(sizeof(struct pos) * N);
	for(i = 0; i < N; i++)
		scanf("%d %d", &dot[i].x, &dot[i].y);

	qsort(dot, N, sizeof(dot[0]), compare);

	for(i = 0; i < N; i++)
		printf("%d %d\n", dot[i].x, dot[i].y);

	free(dot);
	return 0;
}

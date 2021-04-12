#include <stdio.h>
#include <stdlib.h>
#define MAX 50

void test(int ***arr, int N) {
	arr[1][2][3] = 10;
	printf("%d %d %d\n", arr[1][2][2], arr[1][2][3], arr[1][2][4]);
}

int w(int a, int b, int c, int ***arr) {
	if((a <= 0) || (b <= 0) || (c <= 0))
		return 1;
	else if(arr[a - 1][b - 1][c - 1])
		return arr[a - 1][b - 1][c - 1];
	else if((a > 20) || (b > 20) || (c > 20))
		return w(20, 20, 20, arr);
	else if((a < b) && (b < c)) {
		arr[a - 1][b - 1][c - 1] = w(a, b, c-1, arr) + w(a, b-1, c-1, arr) - w(a, b-1, c, arr);
		return arr[a - 1][b - 1][c - 1];
	}
	else {
		arr[a - 1][b - 1][c - 1] = w(a-1, b, c, arr) + w(a-1, b-1, c, arr) + w(a-1, b, c-1, arr) - w(a-1, b-1, c-1, arr);
		return arr[a - 1][b - 1][c - 1];
	}
}

int main() {
	int a, b, c, i, j, k;
	int ***arr;
	arr = (int ***)malloc(sizeof(int **) * MAX);
	for(i = 0; i < MAX; i++) {
		arr[i] = (int **)malloc(sizeof(int *) * MAX);
		for(j = 0; j < MAX; j++) {
			arr[i][j] = (int *)malloc(sizeof(int) * MAX);
			for(k = 0; k < MAX; k++)
				arr[i][j][k] = 0;
		}
	}

	while(1) {
		scanf("%d %d %d", &a, &b, &c);
		if((a == -1) && (b == -1) && (c == -1))
			break;
		printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c, arr));
	}

	for(i = 0; i < MAX; i++) {
		for(j = 0; j < MAX; j++)
			free(arr[i][j]);
		free(arr[i]);
	}
	free(arr);

	return 0;
}

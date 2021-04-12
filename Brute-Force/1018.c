#include <stdio.h>
#include <stdlib.h>

int main() {
	int N, M, i, j, x, y, cnt1, cnt2, cnt, ans;
	char **B;
	scanf("%d %d\n", &N, &M);
	ans = N * M;
	B = (char **)malloc(sizeof(char *) * N);
	B[0] = (char *)malloc(sizeof(char) * (M + 1) * N); // \n때문에 열 1개 추가
	for(i = 0; i < N; i++) {
		if(i)
			B[i] = B[i - 1] + M;
		for(j = 0; j < M + 1; j++)
			scanf("%c", &B[i][j]);
	}
	
	for(x = 0; x <= N - 8; x++) {
		for(y = 0; y <= M - 8; y++) {
			cnt1 = 0;
			cnt2 = 0;
			for(i = x; i < x + 8; i++) {
				for(j = y; j < y + 8; j++) {
					if((i + j) % 2) {
						if(B[i][j] != 'B')
							cnt1++;
						else
							cnt2++;
					}
					else {
						if(B[i][j] != 'W')
							cnt1++;
						else
							cnt2++;
					}
				}
			}
			cnt = cnt1 < cnt2 ? cnt1 : cnt2;
			if(cnt < ans)
				ans = cnt;
		}
	}

	printf("%d\n", ans);

	free(B[0]);
	free(B);
	return 0;
}

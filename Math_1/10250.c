#include <stdio.h>

int main() {
	int T, H, W, N, i, room;
	scanf("%d", &T);

	for(i = 0; i < T; i++) {
		scanf("%d %d %d", &H, &W, &N);
		if(N % H)
			room = (N - (N / H) * H) * 100 + (N / H + 1);
		else
			room = H * 100 + (N / H);
		printf("%d\n", room);
	}
	return 0;
}

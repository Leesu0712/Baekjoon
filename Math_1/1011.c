#include <stdio.h>

int nsum(int n) {
	if(n % 2)
		return (n + 1)*(n / 2) + (n / 2) + 1;
	else
		return (n + 1)*(n / 2);
}

int main() {
	int T, i, j, x, y, pos, prev;
	scanf("%d", &T);
	for(i = 0; i < T; i++) {
		scanf("%d %d", &x, &y);
		pos = x;
		prev = 0;
		for(j = 0; pos < y; j++) {
//			printf("prev = %d y = %d pos = %d nsum(prev) = %d nsum(prev+1) = %d\n", prev, y, pos, nsum(prev), nsum(prev+1));
			if((y - pos) == 1)
				prev = 1;
			else if((y - pos) < nsum(prev))
				prev -= 1;
			else if((y - pos) < nsum(prev + 1))
				;
			else
				prev += 1;
			pos += prev;
//			printf("prev = %d pos = %d\n", prev, pos);
		}
		printf("%d\n", j);
	}
	return 0;
}

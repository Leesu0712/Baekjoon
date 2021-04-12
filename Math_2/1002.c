#include <stdio.h>

int main() {
	int T, x1, x2, y1, y2, r1, r2, sqd, rsum, rdiff, i, ans;
	scanf("%d", &T);

	for(i = 0; i < T; i++) {
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		sqd = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
		rsum = r1 + r2;
		rdiff = r1 - r2;

		if((x1 == x2) && (y1 == y2)) {
			if(r1 == r2)
				ans = -1;
			else
				ans = 0;
		}
		else {
			if(rsum * rsum < sqd)
				ans = 0;
			else if(rsum * rsum == sqd)
				ans = 1;
			else if(rdiff * rdiff < sqd)
				ans = 2;
			else if(rdiff * rdiff == sqd)
				ans = 1;
			else
				ans = 0;
		}

		printf("%d\n", ans);
	}
	return 0;
}

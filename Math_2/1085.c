#include <stdio.h>

int main() {
	int x, y, w, h, xdir, ydir;
	scanf("%d %d %d %d", &x, &y, &w, &h);

	if((w - x) < x)
		xdir = w - x;
	else
		xdir = x;

	if((h - y) < y)
		ydir = h - y;
	else
		ydir = y;

	printf("%d\n", xdir < ydir ? xdir : ydir);

	return 0;
}

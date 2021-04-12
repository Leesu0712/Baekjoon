#include <stdio.h>

struct poscnt {
	int pos;
	int cnt;
};

int main() {
	int i, x, y;
	struct poscnt x1, x2, y1, y2;

	scanf("%d %d", &x, &y);
	x1.pos = x;
	y1.pos = y;

	scanf("%d %d", &x, &y);
	if(x == x1.pos)
		x1.cnt++;
	else
		x2.pos = x;
	if(y == y1.pos)
		y1.cnt++;
	else
		y2.pos = y;

	scanf("%d %d", &x, &y);
	if(x1.cnt)
		x2.pos = x;
	else {
		if(x == x1.pos)
			x1.cnt++;
		else
			x2.cnt++;
	}
	if(y1.cnt)
		y2.pos = y;
	else {
		if(y == y1.pos)
			y1.cnt++;
		else
			y2.cnt++;
	}

	if(x1.cnt) {
		if(y1.cnt) {
			x = x2.pos;
			y = y2.pos;
		}
		else {
			x = x2.pos;
			y = y1.pos;
		}
	}
	else {
		if(y1.cnt) {
			x = x1.pos;
			y = y2.pos;
		}
		else {
			x = x1.pos;
			y = y1.pos;
		}
	}
	printf("%d %d\n", x, y);

	return 0;
}



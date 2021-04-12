#include <stdio.h>

int calc(int n) {
	int i, c;
	int psum = 0;

	c = n;
	for(i = 0; c > 0; i++) {
		psum += c % 10;
		c = c / 10;
	}

	return n + psum;
}

int main() {
	int i, d;
	int check[10000] = { 0, };

	for(i = 0; i < 10000; i++) {
		if(check[i])
			continue;
		d = i + 1;
		while(calc(d) < 10001) {
			d = calc(d);
			check[d-1] = 1;
		}
	}

	for(i = 0; i < 10000; i++) {
		if(!check[i])
			printf("%d\n", i + 1);
	}
	return 0;
}

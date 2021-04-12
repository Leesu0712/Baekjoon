#include <stdio.h>
#define NMAX 50

int main() {
	int i, N[NMAX], P[NMAX], psum = 0, n = 0, ncnt = 0, opcnt = 0;
	char ALL[NMAX * 5 + NMAX], OP[NMAX];
	scanf("%s", ALL);

	for(i = 0; i < NMAX * 5 + NMAX; i++) {
		if(ALL[i] == '\0') {
			N[ncnt++] = n;
			OP[opcnt] = 0;
			break;
		}
		else if((ALL[i] == 43) || (ALL[i] == 45)) {
			OP[opcnt++] = ALL[i];
			N[ncnt++] = n;
			n = 0;
		}
		else
			n = n * 10 + ALL[i] - 48;
	}

	ncnt = 0;
	for(i = 0; i <= opcnt; i++) {
		psum += N[i];
		if((OP[i] == '-') || (OP[i] == 0)) {
			P[ncnt++] = psum;
			psum = 0;
		}
	}

	psum = P[0];
	for(i = 1; i < ncnt; i++)
		psum -= P[i];

	printf("%d\n", psum);

	return 0;
}

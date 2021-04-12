#include <stdio.h>

void order(int* a) {
	int i, j, tmp = 0;

	for(i = 0; i < 2; i++) {
		for(j = 0; j < 2 - i; j++) {
			if(a[j] > a[j + 1]) {
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}

int main() {
	int a[3];

	while(1) {
		scanf("%d %d %d", &a[0], &a[1], &a[2]);
		if(!a[0] && !a[1] && !a[2])
			return 0;
		else {
			order(a);
			if((a[0] * a[0] + a[1] * a[1]) == a[2] * a[2])
				printf("right\n");
			else
				printf("wrong\n");
		}
	}
}

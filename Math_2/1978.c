#include <stdio.h>

int main() {
	int N, i, j, num;
	int pcnt = 0;
	scanf("%d", &N);
	for(i = 0; i < N; i++) {
		scanf("%d", &num);
		for(j = 2; j < num; j++) {
			if(!(num % j)) 
				break;
		}
		if(j == num)
			pcnt++;
	}
	printf("%d\n", pcnt);

	return 0;
}

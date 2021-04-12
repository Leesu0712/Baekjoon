#include <stdio.h>

int main() {
	int N, i, cnt = 0, num, end;
	scanf("%d", &N);

	for(i = 666; cnt < N; i++) {
		num = i;
		while(num) {
			if(num % 10 == 6) {
				if(((num / 10) % 10 == 6) && ((num / 100) % 10 == 6)) {
					cnt++;
					break;
				}
				else
					num = num / 10;
			}
			else {
				num = num / 10;
			}
		}
	}
	printf("%d\n", i - 1);

	return 0;
}

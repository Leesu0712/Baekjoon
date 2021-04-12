#include <stdio.h>
#include <stdlib.h>

int main() {
	int N, i;
	int sum = 0;
	char buf[101];
	char num[2];
	num[1] = '\0';
	scanf("%3d", &N);
	scanf("%s", buf);

	for(i = 0; i < N; i++) {
		num[0] = buf[i];
		sum += atoi(num);
	}
	printf("%d\n", sum);

	return 0;
}


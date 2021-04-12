#include <stdio.h>

int main() {
	int A, B;

	while(1) {
		if(scanf("%d %d", &A, &B) == EOF)
			break;
		else
			printf("%d\n", A+B);
	}
	return 0;
}

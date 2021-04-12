#include <stdio.h>

int main() {
	int year;
	scanf("%d", &year);

	if(!(year%4)) {
		if((year%100) || !(year%400))
			printf("1\n");
		else
			printf("0\n");
	}
	else
		printf("0\n");

	return 0;
}

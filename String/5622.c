#include <stdio.h>

int aton(char a) {
	if((a > 64) && (a < 68))
		return 2;
	else if(a < 71)
		return 3;
	else if(a < 74)
		return 4;
	else if(a < 77)
		return 5;
	else if(a < 80)
		return 6;
	else if(a < 84)
		return 7;
	else if(a < 87)
		return 8;
	else if(a < 91)
		return 9;
	else
		return 0;
}

int main() {
	char a[16];
	scanf("%s", a);
	int i;
	int sec = 0;

	for(i = 0; a[i] != '\0'; i++) {
		sec += (aton(a[i]) + 1);
	}
	printf("%d\n", sec);
	
	return 0;
}

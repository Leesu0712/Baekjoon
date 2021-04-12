#include <stdio.h>
#define StrMAX 100

int main() {
	int i;
	char str[StrMAX+1];
	fgets(str, StrMAX+1, stdin);
	for(i = 0; str[i] != '\0'; i++)
		printf("str[%d] : %c\n", i, str[i]);

	return 0;
}

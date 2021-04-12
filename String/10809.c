#include <stdio.h>

int main() {
	char S[101];
	scanf("%s", S);
	int i;
	int alp[26];
	for(i = 0; i < 26; i++)
		alp[i] = -1;

	for(i = 0; S[i] != '\0'; i++) {
		if(alp[S[i] - 97] == -1)
			alp[S[i] - 97] = i;
	}

	for(i = 0; i < 26; i++) {
		printf("%d ", alp[i]);
	}
	printf("\n");

	return 0;
}

#include <stdio.h>

int main() {
	int T, R, i, j, k;
	char S[21];
	scanf("%d", &T);

	for(i = 0; i < T; i++) {
		scanf("%d %s", &R, S);
		for(j = 0; S[j] != '\0'; j++) {
			for(k = 0; k < R; k++) {
				printf("%c", S[j]);
			}
		}
		printf("\n");
	}

	return 0;
}

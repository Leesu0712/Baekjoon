#include <stdio.h>
#include <stdlib.h>
#define LIMIT 1000
#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
	int i, j, alen, blen, **LCS;
	char a[LIMIT+1], b[LIMIT+1];

	scanf("%s %s", a, b);
	LCS = (int **)malloc(sizeof(int*) * (LIMIT + 1));
	for(i = 0; i <= LIMIT; i++)
		LCS[i] = (int *)malloc(sizeof(int) * (LIMIT + 1));

	for(i = 0; i <= LIMIT; i++) {
		LCS[0][i] = 0;
		LCS[i][0] = 0;
	}

	for(i = 0; a[i] != '\0'; i++)
		;
	alen = i;
	for(i = 0; b[i] != '\0'; i++)
		;
	blen = i;

	for(i = 1; i <= alen; i++) {
		for(j = 1; j <= blen; j++) {
			if(a[i-1] == b[j-1])
				LCS[i][j] = LCS[i-1][j-1] + 1;
			else
				LCS[i][j] = max(LCS[i][j-1], LCS[i-1][j]);
		}
	}
	
	printf("%d\n", LCS[alen][blen]);

	for(i = 0; i <= LIMIT; i++)
		free(LCS[i]);
	free(LCS);

	return 0;
}

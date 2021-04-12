#include <stdio.h>

int main() {
	int N, i, j, gw;
	char word[101];
	scanf("%d", &N);
	int cnt = 0;

	for(i = 0; i < N; i++) {
		scanf("%s", word);
	    char alp[26] = { 0, };
		gw = 1;
		for(j = 0; word[j] != '\0'; j++) {
			if(alp[word[j] - 97] == 0) {
				alp[word[j] - 97] = 1;
			}
			else if (word[j - 1] != word[j]) {
				gw = 0;
				break;
			}
		}
		if(gw)
			cnt++;
	}
	printf("%d\n", cnt);

	return 0;
}

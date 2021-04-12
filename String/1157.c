#include <stdio.h>

int main() {
	char word[1000001];
	int alp[26] = { 0, };
	int i, max, cnt, num;
	scanf("%s", word);

	for(i = 0; word[i] != '\0'; i++) {
		if((word[i] > 64) && (word[i] < 91))
			alp[word[i] - 65]++;
		else
			alp[word[i] - 97]++;
	}

	max = 0;
	for(i = 0; i < 26; i++) {
		if(alp[i] > max)
			max = alp[i];
	}

	cnt = 0;
	for(i = 0; i < 26; i++) {
		if(alp[i] == max) {
			cnt++;
			num = i;
		}
	}

	if(cnt == 1)
		printf("%c\n", num + 65);
	else
		printf("\?\n");

	return 0;
}

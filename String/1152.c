#include <stdio.h>

int main() {
	char S[1000001];
	int i;
	int cnt = 1;
	scanf("%[^\n]s", S);
	for(i = 0; S[i] != '\0'; i++) {
		if((i == 0) && (S[i] == ' ')) {
			if(S[i + 1] == '\0')
				cnt = 0;
			continue;
		}
		else if((S[i] == ' ') && (S[i + 1] == '\0'))
			continue;
		else if(S[i] == ' ')
			cnt++;
	}
	printf("%d\n", cnt);

	return 0;
}

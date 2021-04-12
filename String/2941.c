#include <stdio.h>

int main() {
	char word[101];
	scanf("%s", word);
	int i;
	int cnt = 0;

	for(i = 0; word[i] != '\0'; i++) {
		if(word[i] == 'c') {
			if((word[i + 1] == '=') || (word[i + 1] == '-'))
				continue;
			cnt++;
		}
		else if(word[i] == 'd') {
			if(((word[i + 1] == 'z') && (word[i + 2] == '=')) || (word[i + 1] == '-'))
				continue;
			cnt++;
		}
		else if((word[i] == 'l') || (word[i] == 'n')) {
			if(word[i + 1] == 'j')
				continue;
			cnt++;
		}
		else if((word[i] == 's') || (word[i] == 'z')) {
			if(word[i + 1] == '=')
				continue;
			cnt++;
		}
		else
			cnt++;
	}
	printf("%d\n", cnt);

	return 0;
}

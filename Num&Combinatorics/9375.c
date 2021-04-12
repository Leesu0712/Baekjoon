#include <stdio.h>
#include <string.h>

struct clothes {
	char type[21];
	int cnt;
};

int main() {
	int T, i, n, j, k, sw = 0, index = 0, ans = 1;
	char name[21], type[21];
	struct clothes c[30];
	scanf("%d", &T);
	for(i = 0; i < T; i++) {
		for(j = 0; j < 30; j++) {
			strcpy(c[j].type, "NONE");
			c[j].cnt = 0;
		}
		ans = 1;
		scanf("%d", &n);
		for(j = 0; j < n; j++) {
			scanf("%s %s", name, type);
			for(k = 0; k < 30; k++) {
				if(!strcmp(type, c[k].type)) {
					c[k].cnt++;
					sw = 1;
					break;
				}
				else if(!strcmp("NONE", c[k].type)) {
					index = k;
					break;
				}
			}
			
			if(!sw) {
				strcpy(c[index].type, type);
				c[index].cnt++;
			}
			sw = 0;
		}
		for(k = 0; k < 30; k++) {
			if(!strcmp(c[k].type, "NONE"))
				break;
			ans *= (c[k].cnt + 1);
		}
		printf("%d\n", ans - 1);
	}
	return 0;
}

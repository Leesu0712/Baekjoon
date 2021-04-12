#include <stdio.h>
#define TMAX 10000

int main() {
	int T, i, a = 1, b = 1, ans;
	while(1) {
		scanf("%d %d", &a, &b);
		if((a == 0) && (b == 0))
			break;
		if(a < b) {
			if(b % a)
				ans = 2;
			else
				ans = 0;
		}
		else {
			if(a % b)
				ans = 2;
			else
				ans = 1;
		}
		switch(ans){
			case 0 :
				printf("factor\n");
				break;
			case 1 :
				printf("multiple\n");
				break;
			case 2 :
				printf("neither\n");
				break;
		}
	}
	return 0;
}

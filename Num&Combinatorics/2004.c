#include <stdio.h>
#define MAX 2000000000

long long twocnt(int n) {
	int a, b;
	long long i, cnt = 0;
	for(i = 2; i <= n; i *= 2)
		;
	a = i / 2;
	for(i = n; i % 2; i--)
		;
	b = i;

	while(a != 1) {
		cnt += b / a;
		a = a / 2;
	}
	return cnt;
}

long long fivecnt(int n) {
	int a, b;
	long long i, cnt = 0;
	for(i = 5; i <= n; i *= 5)
		;
	a = i / 5;
	for(i = n; i % 5; i--)
		;
	b = i;

	while(a != 1) {
		cnt += b / a;
		a = a / 5;
	}
	return cnt;
}

int main() {
	int n, m;
	long long two, five;
	scanf("%d %d", &n, &m);

	two = twocnt(n) - twocnt(m) - twocnt(n-m);
	five = fivecnt(n) - fivecnt(m) - fivecnt(n-m);
	printf("%lld\n", two < five ? two : five);

	return 0;
}

#include <stdio.h>
#define MAX 500

struct cnt {
    int two;
    int five;
};

int division(int a, int b) {
    int cnt = 0;
    while(!(a % b)) {
        cnt++;
        a = a / b;
    }
    return cnt;
}

int main() {
    int N, i;
    struct cnt cnt[MAX+1];
    scanf("%d", &N);
    cnt[0].two = 0;
    cnt[0].five = 0;
    for(i = 1; i <= N; i++) {
        if(!(i % 2) && !(i % 5)) {
            cnt[i].two = cnt[i-1].two + division(i, 2);
            cnt[i].five = cnt[i-1].five + division(i, 5);
        }
        else if (!(i % 2)) {
            cnt[i].two = cnt[i-1].two + division(i, 2);
            cnt[i].five = cnt[i-1].five;
        }
        else if (!(i % 5)) {
            cnt[i].two = cnt[i-1].two;
            cnt[i].five = cnt[i-1].five + division(i, 5);
        }
        else {
            cnt[i].two = cnt[i-1].two;
            cnt[i].five = cnt[i-1].five;
        }
    }
    printf("%d\n", cnt[N].two < cnt[N].five ? cnt[N].two : cnt[N].five);
    return 0;
}

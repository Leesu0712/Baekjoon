#include <stdio.h>
  
int main() {
    int N, i, j, k;
    scanf("%d", &N);

    for(i = 1; i <= N; i++) {
        for(k = N - i; k > 0; k--)
            printf(" ");
        for(j = 1; j <= i; j++)
            printf("*");
        printf("\n");
    }
    return 0;
}

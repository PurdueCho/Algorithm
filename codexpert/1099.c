#include <stdio.h>

int N;
int a[1000 + 10]; // 1000000 10^7
int sol;

int max = 0;
int cur = 9999999;
int root;

int DRoot( int num ) {
    int ret=0, input = num;

    while(input) {
        ret += input % 10;
        input /= 10;
    }
    //printf("DR: %d\n", ret);
    return ret;
}


void Solve( int num ) {
    int ret = num;
    
    while (ret / 10 > 0) {
        //printf("Now: %d\n", ret);
        ret = DRoot(ret);
    }

    if (ret > max) {
        max = ret;
        cur = num;    
    }

    if (ret == max && num < cur) {
        cur = num;
    }

    //printf("Max: %d\n", max);
    //printf("Min: %d\n", cur);
}

int main(void)
{
    int i;

    // 입력받는 부분
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }

    // 여기서부터 작성
    for (i = 0 ; i < N; i ++) {
        Solve(a[i]);
    }

    sol = cur;

    // 출력하는 부분
    printf("%d", sol);

    return 0;
}

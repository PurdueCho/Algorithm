#include <stdio.h>

int N; // 1000
int sol;
int a[1000 + 1] = {0,};

int Calculate( int num ) {
    int sum = 0, input = num;

    while (input) {
        sum += (input % 10) * (input % 10);
        input /= 10;
    }

    //printf("%d\n", sum);

    return sum;
}

int isHappy( int num ) {

    for (int i = 0; i < 1001 ; i++) {
        a[i] = 0;
    }

    int res = num;

    while (res != 1) {
        res = Calculate (res);
        if (a[res] == 1) {
            return 0;
        } else {
            a[res] = 1;
        }
    }
    return 1;

}


int main(void)
{
    // 입력받는 부분
    scanf("%d", &N);

    // 여기서부터 작성
    int i, flag = 0;
    int max = -1;

    for (i = N ; i > 0; i--) {
        if (isHappy(i)) {
            if (max < i) max = i;
            //printf("%d\n", i);
        }
    }

    // 출력하는 부분
    printf("%d", max);

    return 0;
}
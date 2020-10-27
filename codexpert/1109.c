#include <stdio.h>

int a, b;

int Jin (int num) {
    int sum = 0;
    for (int i = 1; i < num ; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return sum; // 진약수의 합
}


void Solve() {
    int cnt = 0;
    int ret;
    int temp;

    // 진약수의 합
    for (int cur = a ; cur <= b; cur++) {
        ret = Jin(cur);
        //printf("진약수: %d\n", ret);

        if (ret == cur) {
            cnt++; // 완전수
        }

        if (ret >= a && ret <= b && ret != cur) {
            temp = Jin(ret);
            if (temp == cur) { // 우정수
                cnt ++;
            }
        }
    }

    printf("%d\n", cnt);

    // 진약수의 합
    for (int cur = a ; cur <= b; cur++) {
        ret = Jin(cur);
        //printf("진약수: %d\n", ret);

        if (ret == cur) {
            cnt++; // 완전수
            printf("%d\n", ret);
        }

        if (ret >= a && ret <= b && ret != cur) {
            temp = Jin(ret);
            if (temp == cur) { // 우정수
                cnt ++;
                printf("%d %d\n", cur, ret);
            }
        }
    }
    
}

int main(void)
{
    // 입력받는 부분
    scanf("%d %d", &a, &b);

    // 여기서부터 작성
    Solve();


    return 0;
}
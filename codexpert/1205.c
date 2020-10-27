#include <stdio.h>
#include <math.h>

int N;      // 정수
int sol;

int Solve (int n ) {
    int i;
    int value = n;
    
    for (i = 0; value != 0; i++)
    {
        value &= (value - 1);
    }
    return i;
}

int main(void)
{

    // 입력받는 부분
    scanf("%d", &N);

    // 여기서부터 작성
    for (int i = 1 ; i <= N; i++) {
        sol += Solve(i);
    }
    

    // 출력하는 부분
    printf("%d", sol);

    return 0;
}
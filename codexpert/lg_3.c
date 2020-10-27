#include <stdio.h>

int N;              //LED 수
int S[100000 + 10]; //LED 상태

void Input_Data(void)
{
    int i;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &S[i]);
    }
}

int main(void)
{
    int ans = -1;
    Input_Data(); //	입력 함수

    //	코드를 작성하세요

    printf("%d\n", ans); //	정답 출력
    return 0;
}

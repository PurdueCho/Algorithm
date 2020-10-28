#include <stdio.h>

int N;          //직원 수
int M;          //기부금 총액
int A[1000010]; //직원 별 성과급

void Input_Data(void)
{
    int i;
    scanf("%d %d", &N, &M);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
}

int main(void)
{
    int ans = 0;
    Input_Data(); //	입력 함수

    //	코드를 작성하세요

    printf("%d\n", ans); //	정답 출력
    return 0;
}

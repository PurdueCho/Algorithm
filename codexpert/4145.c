#include <stdio.h>
int N;              //마을 수
int A[100000 + 10]; //마을 위치
int B[100000 + 10]; //잡힌 물고기 양

void InputData(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &A[i], &B[i]);
    }
}
int main(void)
{
    int ans = -1;
    InputData(); //입력받는부분

    //여기서부터작성

    printf("%d\n", ans); //출력하는부분
    return 0;
}
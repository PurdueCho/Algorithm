#include <stdio.h>
int N;               //젖소의 수
int P[100000 + 10];  //젖소 위치
char M[100000 + 10]; //소의 종류

void InputData()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %c", &P[i], &M[i]);
    }
}
int main()
{
    int ans = -1;
    InputData(); //입력받는부분

    //여기서부터작성

    printf("%d\n", ans); //출력하는부분
    return 0;
}
#include <stdio.h>
#define MAXN (102)
int N;      //산크기
int eh, ew; //정상 위치 세로, 가로
int map[MAXN][MAXN];
void InputData(void)
{
    scanf("%d", &N);
    scanf("%d %d", &eh, &ew);
    for (int h = 1; h <= N; h++)
    {
        for (int w = 1; w <= N; w++)
        {
            scanf("%d", &map[h][w]);
        }
    }
}

int main(void)
{
    int ans = -1;
    InputData(); //입력 받는 부분

    //여기서부터 작성

    printf("%d\n", ans); //출력하는 부분
    return 0;
}
#include <stdio.h>
#define MAXN (100)
int W, H;                       //지도의 가로 세로 크기
char map[MAXN + 10][MAXN + 10]; //지도 정보('1':저글링, '0':빈곳)
int sw, sh;                     //시작위치 가로 세로 좌표
void InputData(void)
{
    scanf("%d %d", &W, &H);
    for (int i = 1; i <= H; i++)
    {
        scanf("%s", &map[i][1]);
    }
    scanf("%d %d", &sw, &sh);
}

int main(void)
{
    InputData(); //입력 받는 부분

    //여기서부터 작성

    return 0;
}
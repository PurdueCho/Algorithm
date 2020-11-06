#include <stdio.h>
int N; //필터 한 변의 크기
int L; //LED의 범위(길이)
int M; //살균대상의 개수

typedef struct
{
    int r, c; //살균대상의 세로, 가로
} FISH;

FISH fish[100 + 10]; //살균대상 좌표

void InputData()
{
    scanf("%d %d %d", &N, &L, &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &fish[i].r, &fish[i].c);
    }
}

int fishcount(int sr, int sc, int er, int ec)
{
    int cnt = 0;
    for (int i = 0; i < M; i++)
    { //살균 대상 중에 영역에 포함되는 살균 대상 개수 파악
        if ((sr <= fish[i].r) && (fish[i].r <= er) && (sc <= fish[i].c) && (fish[i].c <= ec))
            cnt++;
    }
    return cnt;
}

int Solve()
{
    int maxv = 0, w, h, e = L / 2;
    for (w = 1; w < e; w++)
    {              //LED의 가로 길이 (모양)
        h = e - w; //LED의 높이
        for (int i = 0; i < M; i++)
        { //살균 대상 베이스 위치(살균 대상 위치)
            for (int offset = w; offset >= 0; offset--)
            {
                int cnt = fishcount(fish[i].r, fish[i].c - offset, fish[i].r + h, fish[i].c - offset + w);
                if (maxv < cnt)
                    maxv = cnt;
            }
        }
    }
    return maxv;
}

int main()
{
    InputData();
    int ans = Solve();
    printf("%d\n", ans);
    return 0;
}
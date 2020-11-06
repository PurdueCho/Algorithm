#include <stdio.h>
int N;           //정사각형 지도 크기
int X, Y;        //수돗물 공급되는 시작 좌표,  가로,  세로
int map[20][20]; //지도 정보
int visited[20][20];
int pipe;

//0:상,  1:하,  2:좌,  3:우
int dh[] = {-1, 1, 0, 0};
int dw[] = {0, 0, -1, 1};

//A[모양번호][해당방향]=확산 여부 확인(1:가능,  0:불가)
int A[][4] = {{0, 0, 0, 0},  //0
              {0, 0, 1, 1},  //1
              {1, 1, 0, 0},  //2
              {0, 1, 0, 1},  //3
              {0, 1, 1, 0},  //4
              {1, 0, 1, 0},  //5
              {1, 0, 0, 1},  //6
              {1, 1, 0, 1},  //7
              {0, 1, 1, 1},  //8
              {1, 1, 1, 0},  //9
              {1, 0, 1, 1},  //10(A)
              {1, 1, 1, 1}}; //11(B)

void FloodFill(int h, int w)
{
    visited[h][w] = 1;   //방문표시(중복방문 방지용)
    pipe--;              //연결된 파이프이므로 개수 감소
    int cur = map[h][w]; //현재 격자의 파이프 모양
    for (int dir = 0; dir < 4; dir++)
    {
        int nh = h + dh[dir];
        int nw = w + dw[dir];
        if ((nh < 0) || (nh >= N) || (nw < 0) || (nw >= N))
            continue; //범위 벗어남
        if (visited[nh][nw] == 1)
            continue; //이미 방문했음
        if (A[cur][dir] == 0)
            continue;           //해당 방향으로 연결 안되있음
        int next = map[nh][nw]; //갈곳의 파이프 모양
        if (A[next][dir ^ 1] == 0)
            continue; //갈곳 격자의 파이프가 (h,  w)격자랑 연결 안되어있음
        FloodFill(nh, nw);
    }
}

int Solve()
{
    //1.파이프 개수 파악
    pipe = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] != 0)
                pipe++;
        }
    }
    //2.시작위치에서 확산
    FloodFill(Y, X);
    return pipe;
}

void Input_Data(void)
{
    int i, j;
    scanf("%d", &N);
    scanf("%d %d", &X, &Y);
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            scanf("%1x", &map[i][j]);
        }
    }
}
int main(void)
{
    int ans = -1;
    Input_Data();        //  입력 함수
    ans = Solve();       //    코드를 작성하세요
    printf("%d\n", ans); //  정답 출력
    return 0;
}
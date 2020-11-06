#include <stdio.h>
#define MAXN (50)
int H;                     // 세로크기
int W;                     // 가로크기
int map[50 + 10][50 + 10]; // 지도 데이터
typedef struct
{
    int h, w, t; //세로, 가로, 거리
} QUE;

QUE que[MAXN * MAXN + 10];
int wp, rp;

int empty() { return wp == rp; }
QUE front() { return que[rp]; }
void pop() { rp++; }

void push(int h, int w, int t)
{
    map[h][w] = 2; //방문표시
    que[wp].h = h;
    que[wp].w = w;
    que[wp].t = t;
    wp++;
}

void FloodFill(int r, int c)
{
    static int dr[] = {-1, 1, 0, 0};
    static int dc[] = {0, 0, -1, 1};
    if ((r < 1) || (r > H) || (c < 1) || (c > W))
        return;
    if (map[r][c] != 1)
        return;
    push(r, c, 0);
    for (int i = 0; i < 4; i++)
        FloodFill(r + dr[i], c + dc[i]);
}

void SaveStart()
{
    for (int r = 1; r <= H; r++)
    {
        for (int c = 1; c <= W; c++)
        {
            if (map[r][c] == 1)
            {
                FloodFill(r, c); //한 영역이 모두 시작점임
                return;
            }
        }
    }
}

int BFS()
{
    int dh[] = {-1, 1, 0, 0};
    int dw[] = {0, 0, -1, 1};
    //1.초기화
    wp = rp = 0;
    //2.시작위치 큐에 저장
    SaveStart();
    //3.반복문
    while (!empty())
    {
        QUE cur = front();
        pop();
        for (int i = 0; i < 4; i++)
        {
            int nh = cur.h + dh[i];
            int nw = cur.w + dw[i];
            if ((nh < 1) || (nh > H) || (nw < 1) || (nw > W))
                continue; //범위 벗어남
            if (map[nh][nw] == 1)
                return cur.t; //도착 성공
            if (map[nh][nw] == 2)
                continue; //이미 방문했음
            push(nh, nw, cur.t + 1);
        }
    }

    //4.실패 (이 문제는 이런 경우 없음)
    return -1; //디버깅을 위해...
}

void InputData(void)
{
    int i, j;
    scanf("%d %d", &H, &W);
    for (i = 1; i <= H; i++)
    {
        for (j = 1; j <= W; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
}

int main(void)
{
    int ans = -1;
    InputData();         //입력 함수
    ans = BFS();         // 코드를 작성 하세요
    printf("%d\n", ans); //출력
    return 0;
}
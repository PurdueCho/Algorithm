#include <stdio.h>
#define MAXN (500)
int W, H;                          //가로,  세로 크기
int sw, sh, ew, eh;                //출발 가로세로,  도착 가로세로 좌표
char map[MAXN + 10][MAXN + 10];    //지도정보
int visited[MAXN + 10][MAXN + 10]; //경험표시(방문표시),  중복경험방지용(표시용)

//linear queue
typedef struct
{
    int h, w, t; //세로,  가로,  시간
} QUE;
QUE que[MAXN * MAXN + 10]; //경험개수 만큼 확보(visited배열 요소수 만큼)
int wp, rp;
void pop() { rp++; }
QUE front() { return que[rp]; }
int empty() { return wp == rp; }

void push(int h, int w, int t)
{
    //if((h<1)||(h>H)||(w<1)||(w>W)) return;//범위 벗어남
    if (map[h][w] != '.')
        return; //길아님(범위 체크 + 장애물 체크)
    if (visited[h][w] == 1)
        return;        //이미 경험했었음
    visited[h][w] = 1; //경험표시
    que[wp].h = h;
    que[wp].w = w;
    que[wp].t = t;
    wp++;
}

int BFS()
{
    int dh[] = {-1, 1, 0, 0};
    int dw[] = {0, 0, -1, 1};
    QUE cur;
    //1.초기화
    wp = rp = 0;
    //2.시작위치 큐에 저장
    push(sh, sw, 0);
    //3.반복문
    while (!empty())
    {
        cur = front();
        pop();
        if ((cur.h == eh) && (cur.w == ew))
            return cur.t; //도착 성공
        for (int i = 0; i < 4; i++)
        {
            push(cur.h + dh[i], cur.w + dw[i], cur.t + 1);
        }
    }
    //4.실패(이문제는 이런 경우 없음)
    return -1; //디버깅위해...
}

void InputData()
{
    scanf("%d %d", &H, &W);
    for (int i = 1; i <= H; i++)
    {
        scanf("%s", &map[i][1]);
    }
    sh = 1;
    sw = 1;
    eh = H;
    ew = W;
}

int main()
{
    InputData();
    int ans = BFS();
    printf("%d\n", ans);
    return 0;
}
#include <stdio.h>
#define INF (100 * 100 * 10)
int N;                 //지도 크기
char map[110][110];    //지도 정보
int visited[110][110]; //누적가중치
//linear queue
typedef struct
{
    int h, w; //세로,  가로 좌표
} QUE;

QUE que[100 * 100 * 10]; //중복방문 하므로 상하좌우로 확산하니까 10배 정도
int wp, rp;

QUE front() { return que[rp]; }
void pop() { rp++; }
int empty() { return wp == rp; }

void push(int h, int w, int t)
{
    if (visited[h][w] <= t)
        return;
    visited[h][w] = t;
    que[wp].h = h;
    que[wp].w = w;
    wp++;
}

int BFS()
{
    int dh[] = {-1, 1, 0, 0}; //상하좌우
    int dw[] = {0, 0, -1, 1};
    QUE cur;
    //1.초기화
    wp = rp = 0;
    for (int h = 0; h < N; h++)
    {
        for (int w = 0; w < N; w++)
        {
            visited[h][w] = INF;
        }
    }
    //2.시작위치 큐에 저장
    push(0, 0, 0);
    //3.반복문(큐가 빌때까지)
    while (!empty())
    {
        cur = front();
        pop();
        for (int i = 0; i < 4; i++)
        {
            int nh = cur.h + dh[i];
            int nw = cur.w + dw[i];
            if ((nh < 0) || (nh >= N) || (nw < 0) || (nw >= N))
                continue; //범위 벗어남,  항상 범위 체크부터
            push(nh, nw, visited[cur.h][cur.w] + map[nh][nw] - '0');
        }
    }
    //4.결과
    return visited[N - 1][N - 1];
}
void Input_Data()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%s", map[i]);
    }
}
int main()
{
    int ans = -1;
    Input_Data();        //  입력 함수
    ans = BFS();         //  코드를 작성하세요
    printf("%d\n", ans); //  정답 출력
    return 0;
}
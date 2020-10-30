#include <stdio.h>
#define MAXN (100)
#define INF ((int)2e9)
int L; //정비를 받지 않고 갈수있는 최대거리
int N; //정비소 개수
//[0]:출발위치, [1~N]:정비소, [N+1]:도착위치
int dist[MAXN + 10];    //정비소사이거리(i-1 ~ i)거리
int time[MAXN + 10];    //정비시간
int visited[MAXN + 10]; //가중치(누적정비시간)
int cnt[MAXN + 10];     //방문한 정비소 개수(인쇄할때 -1해야함, 도착위치도 계산됨)
int path[MAXN + 10];    //이전 정비소 번호(역추적 하면 경로 파악, 출발도착위치 인쇄 안함)
//linear queue
int que[MAXN * 100]; //중복방문하므로 100배
int wp, rp;
void push(int n, int t, int c, int p)
{ //방문(확산) 정비소 번호, 가중치, 방문횟수, 이전정비소번호)
    if (visited[n] <= t)
        return; //이전보다 안좋음
    que[wp++] = n;
    visited[n] = t;
    cnt[n] = c;
    path[n] = p;
}
void pop() { rp++; }
int front() { return que[rp]; }
int empty() { return wp == rp; }
void BFS()
{
    //1.초기화
    wp = rp = 0;
    for (int i = 0; i <= N + 1; i++)
    {
        visited[i] = INF;
    }
    //2.시작위치 큐에 저장
    push(0, 0, 0, 0);
    //3.반복문
    while (!empty())
    {
        int cur = front();
        pop();
        int sumdist = 0;
        for (int e = cur + 1; e <= N + 1; e++)
        {
            sumdist += dist[e]; //e-1 ~ e거리
            if (sumdist > L)
                break; //정비 받지 않고 갈수있는 최대거리 초과
            push(e, visited[cur] + time[e], cnt[cur] + 1, cur);
        }
    }
}
void PRT(int m)
{
    if (m == 0)
        return;
    PRT(path[m]);
    printf("%d ", m);
}
void OutputData()
{
    if (visited[N + 1] == 0)
    { //정비소를 들리지 않아도 되는 경우
        printf("0\n");
    }
    else
    {
        printf("%d\n", visited[N + 1]);
        printf("%d\n", cnt[N + 1] - 1);
        PRT(path[N + 1]);
        printf("\n");
    }
}
void InputData(void)
{
    scanf("%d", &L);
    scanf("%d", &N);
    for (int i = 1; i <= N + 1; i++)
    {
        scanf("%d", &dist[i]);
    }
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &time[i]);
    }
}
int main(void)
{
    InputData();  //입력 받는 부분
    BFS();        //여기서부터 작성
    OutputData(); //출력
    return 0;
}
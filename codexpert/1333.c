#include <stdio.h>
#define MAXN (100)
#define MAXL ((int)1e6)
#define INF (MAXN * MAXL)
int N, M;                       //노드개수, 길개수
int dist[MAXN + 10][MAXN + 10]; //[출발][도착]=거리
int visited[MAXN + 10];         //누적가중치
int path[MAXN + 10];            //경로(이전 노드번호)
int firstpath[MAXN + 10];       //농부 존의 평소 경로
int firstcnt;                   //경로상 노드 개수
//linear queue
int que[MAXN * 100];
int wp, rp;
int front() { return que[rp]; }
void pop() { rp++; }
int empty() { return wp == rp; }
void push(int n, int t, int pre)
{
    if (visited[n] <= t)
        return;
    visited[n] = t;
    path[n] = pre;
    que[wp++] = n;
}
int BFS()
{
    //1.초기화
    wp = rp = 0;
    for (int i = 1; i <= N; i++)
        visited[i] = INF;
    //2.큐에 시작 위치 저장
    push(1, 0, 0);
    //3.반복문
    while (!empty())
    {
        int cur = front();
        pop();
        for (int e = 1; e <= N; e++)
        {
            if (dist[cur][e] == 0)
                continue; //cur => e 길 없음, skip
            push(e, visited[cur] + dist[cur][e], cur);
        }
    }
    //4.결과
    return visited[N];
}
void SAVE(int n)
{
    if (n == 0)
        return;
    SAVE(path[n]);
    firstpath[firstcnt++] = n;
}
int Solve()
{
    int maxv = 0; //새로운 경로 길이 - 기존 경로 길이 중 최댓값
    //1.농부 존의 평소 경로 구하기(최단 거리)
    int first = BFS();
    firstcnt = 0;
    SAVE(N);
    //2.평소 경로상의 길들을 하나씩 두배로 변경해보면서 답 찾기
    for (int i = 0; i < firstcnt - 1; i++)
    {
        int s = firstpath[i];
        int e = firstpath[i + 1];
        if (maxv >= dist[s][e])
            continue;                 //기댓값이 이전 답보다 안좋으므로 skip(가지치기)
        dist[s][e] = dist[e][s] *= 2; //2배 바꾸기
        int second = BFS();
        if (maxv < second - first)
            maxv = second - first;
        dist[s][e] = dist[e][s] /= 2; //원상복귀
    }
    return maxv;
}
void InputData()
{
    int A, B, L;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &A, &B, &L);
        dist[A][B] = dist[B][A] = L; //노드간 길이 최대 1개이고 양방향 길이므로...
    }
}
int main()
{
    InputData();
    int ans = Solve();
    printf("%d\n", ans);
    return 0;
}
#include <stdio.h>
#define MAXN (100)
#define INF (MAXN * 100)
int N, M;                       //공장수,  도로정보수
int dist[MAXN + 10][MAXN + 10]; //[출발노드][도착노드]=거리정보
int visited[MAXN + 10];

//linear Queue
int que[MAXN * 100];
int wp, rp;

void push(int n, int t)
{
    if (visited[n] <= t)
        return;
    visited[n] = t;
    que[wp++] = n;
}
void pop() { rp++; }
int front() { return que[rp]; }
int empty() { return wp == rp; }

int BFS(int s)
{
    //1.초기화
    wp = rp = 0;
    for (int i = 1; i <= N; i++)
        visited[i] = INF;
    //2.시작위치 큐에 저장
    push(s, 0);
    //3.반복문
    while (!empty())
    {
        int cur = front();
        pop();
        for (int e = 1; e <= N; e++)
        {
            if (dist[cur][e] == 0)
                continue; //0이면 연결안되어있음
            push(e, visited[cur] + dist[cur][e]);
        }
    }
    //4.결과
    int idx = 1;
    for (int i = 2; i <= N; i++)
    {
        if (visited[idx] < visited[i])
            idx = i;
    }
    return visited[idx];
}

int Solve()
{                  //모든 장소(공장)에다 물류창고 지어보기
    int sol = INF; //최솟값을 구하므로 최댓값으로 초기화
    for (int s = 1; s < N; s++)
    {                   //출발 공장 번호
        int t = BFS(s); //s에서 가장 먼 공장과의 거리
        if (sol > t)
            sol = t;
    }
    return sol;
}

void InputData()
{
    int a, b, d;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &a, &b, &d);
        dist[a][b] = dist[b][a] = d; //양방향 도로이므로..
    }
}
int main()
{
    InputData();
    int ans = Solve();
    printf("%d\n", ans);
    return 0;
}
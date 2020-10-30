#include <stdio.h>
#define MAXN (128)
#define INF (MAXN * 1000)
int dist[MAXN][MAXN]; //[출발][도착]=거리
int visited[MAXN];    //누적가중치
//linear queue
char que[MAXN * 100];
int wp, rp;
void push(char n, int t)
{
    if (visited[n] <= t)
        return;
    visited[n] = t;
    que[wp++] = n;
}
char front() { return que[rp]; }
void pop() { rp++; }
int empty() { return wp == rp; }
char BFS()
{
    //1.초기화
    wp = rp = 0;
    for (char i = 'A'; i <= 'z'; i++)
        visited[i] = INF;
    //2.시작위치 큐에 저장
    push('Z', 0);
    //3.반복문(큐가 빌때까지 확산, 가중치가 다르므로)
    while (!empty())
    {
        char cur = front();
        pop();
        for (char e = 'A'; e <= 'z'; e++)
        {
            if (dist[cur][e] == 0)
                continue; //cur => e 길 없음
            push(e, visited[cur] + dist[cur][e]);
        }
    }
    //4.결과('A'~'Y' 최솟값을 갖는 인덱스를 찾기)
    char idx = 'A'; //최솟값이 'A'라 가정
    for (char i = 'B'; i <= 'Y'; i++)
    {
        if (visited[idx] > visited[i])
            idx = i;
    }
    return idx;
}
void InputData()
{
    int P;
    char s, e;
    int d;
    scanf("%d", &P);
    for (int i = 0; i < P; i++)
    {
        scanf(" %c %c %d", &s, &e, &d);
        if ((dist[s][e] == 0) || (dist[s][e] > d))
        {
            dist[s][e] = dist[e][s] = d; //양방향길이므로...
        }
    }
}
int main()
{
    InputData();
    char ans = BFS();
    printf("%c %d\n", ans, visited[ans]);
    return 0;
}
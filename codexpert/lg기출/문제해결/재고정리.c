//시간복잡도 O(M!) + 가지치기
#include <stdio.h>
#define MAXN ((int)1e5)
#define MAXM (10)
int N;               //제품 수
int M;               //제품 종류 수
int ID[100000 + 10]; //제품 ID
int sol;
int used[MAXM + 10];
int dcnt[MAXM + 10];
int presum[MAXM + 10][MAXN + 10];

void InputData()
{
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &ID[i]);
    }
}

void DFS(int n, int p, int cnt)
{ //순서, 놓일 시작위치, 옮긴수
    if (sol <= cnt)
        return; //가지치기
    if (n > M)
    {
        sol = cnt;
        return;
    }

    for (int i = 1; i <= M; i++)
    {
        if (used[i] == 1)
            continue; //이미 선택한 종류임
        used[i] = 1;  //사용으로 표시
        int mov = dcnt[i] - (presum[i][p + dcnt[i] - 1] - presum[i][p - 1]);
        DFS(n + 1, p + dcnt[i], cnt + mov);
        used[i] = 0; //표시 제거
    }
}

int Solve()
{
    //1.제품 종류별 개수 구하기
    for (int i = 1; i <= N; i++)
    {
        dcnt[ID[i]]++;
        presum[ID[i]][i] = 1;
    }
    //2.구간합 구하기
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            presum[i][j] += presum[i][j - 1];
        }
    }
    sol = N;      //최소값구하므로 최대값으로 초기화
    DFS(1, 1, 0); //순서, 놓일 시작위치, 옮긴수
    return sol;
}

int main()
{
    InputData();
    int ans = Solve();
    printf("%d\n", ans);
    return 0;
}
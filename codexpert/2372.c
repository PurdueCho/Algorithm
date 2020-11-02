#include <stdio.h>
#define MAXN (10)

int N;
int cost[MAXN + 10][MAXN + 10];

int check[MAXN + 10];
int path[MAXN + 10];

int solpath[MAXN + 10]; //답 경로
int sol = 9999999;



void InputData(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }
}

void OutputData(int sol)
{
    printf("%d\n", sol);
    for (int i = 0; i < N; i++)
    {
        printf("%d ", solpath[i]);
    }
    printf("\n");
}

void DFS ( int idx , int sum) {

    //printf("%d\n", idx);
    // BASE
    if (idx == N) {
        
        sol = sum;
        for (int i = 0 ; i < N; i++) {
            solpath[i] = path[i] + 1;
        }
        return;
    }

    for (int i = 0 ; i < N; i++) {
        
        if (check[i] == 1) continue;
        if (sum + cost[idx][i] > sol ) continue;

        //printf("Building: %d Location: %d Cost: %d\n", idx, i, sum);

        check[i] = 1;
        path[idx] = i;
        DFS(idx + 1, sum + cost[idx][i]);
        check[i] = 0;
        path[idx] = -1;
    }
}

void Solve() {

    DFS(0,0);

}

int main(void)
{
    int ans = -1;

    InputData(); //입력받는 부분

    //여기서부터 작성
    Solve();
    ans = sol;

    OutputData(ans); //출력하는 부분
    return 0;
}
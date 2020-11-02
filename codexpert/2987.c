#include <stdio.h>
#include <stdlib.h>
#define MAXN (20)

int N, B;
int H[MAXN + 10];
int check[MAXN + 10];
int idx_check[MAXN + 10];
int sol = 999999;

void InputData(void)
{
    scanf("%d %d", &N, &B);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &H[i]);
    }
}

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void DFS(int idx, int sum) {

    if (idx >= N || sum >= B ) { //base
        if (sum >= B && sum < sol) sol = sum;
        return;
    }

    DFS (idx+1, sum + H[idx]);
    DFS (idx+1, sum);
}

void Solve() {

    for (int i = 0 ; i < N ; i++) {
        check[i] = 0;
    }
    sol = 999999;

    //qsort(H, N, sizeof(int), compare);

    DFS(0, 0);
}

int main(void)
{
    int T, ans = -1;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++)
    {
        InputData(); //입력받는 부분

        //여기서부터 작성
        Solve();
        ans = abs(B - sol);

        printf("%d\n", ans);
    }
    return 0;
}
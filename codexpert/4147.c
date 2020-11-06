#include <stdio.h>
#define MAXB (9)
#define MAXN ((int)1e5)

int B, N;
int S[MAXB + 10];
int visited[MAXB + 10];
int P[MAXN + 10];
int P_sum[MAXN + 10];
int total;
int ret;

void InputData(void)
{
    scanf("%d %d", &B, &N);
    for (int i = 0; i < B; i++)
    {
        scanf("%d", &S[i]);
        total += S[i];
    }
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &P[i]);
        P_sum[i+1] = P[i] + P_sum[i];
    }
}

int BS(int s, int p) {
    int start = s, end = N;
    int bound = -1;

    while (start <= end) {
        int mid = (start+end)/2;
        int w = P_sum[mid] - P_sum[s];

        if (w > p) {
            end = mid - 1;
        } else if (w == p) {
            return mid;
        } else {
            bound = mid;
            start = mid+1;
        }
    }
    return bound;
}

void DFS(int remain, int total, int start) {

    if (total <= ret) {
        return;
    }

    if (remain <= 0) {
        ret = total;
        return;
    }

    for (int i = 0 ; i < B ; i++) {
        if (visited[i]) {
            continue;
        }

        int end = BS(start, S[i]);

        if (end == -1) continue;

        visited[i] = 1;
        DFS(remain - (end - start), total - S[i], end);
        visited[i] = 0;
    }
}

int main(void)
{
    int ans = -1;

    InputData(); //입력받는 부분

    //여기서부터 작성
    if (P_sum[N] > total) {
        ans = -1;
    } else {
        DFS(N, total, 0);
        ans = ret;
    }

    printf("%d\n", ans); //출력하는 부분
    return 0;
}
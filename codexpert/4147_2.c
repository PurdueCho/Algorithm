#include <stdio.h>
int B, N, totalWeight;
int boat[10], visit[10];
int passenger[100000], psum[100001];
int ans = -1;

// Upper Bound 탐색
int findBound(int s, int pivot)
{
    int start = s, end = N;
    int bound = -1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        int w = psum[mid] - psum[s];
        // 설정한 인원만큼 탑승하지 못하는 경우
        if (w > pivot)
            end = mid - 1;
        // 일치하는 경우
        else if (w == pivot)
            return mid;
        else
        {
            bound = mid;
            start = mid + 1;
        }
    }
    return bound;
}

void DFS(int remain, int totalWeight, int s)
{
    // 현재 출항하지 않은 배의 무게가 이미 구한 값(ans)보다 작은 경우
    if (totalWeight <= ans)
        return;
    // 모든 인원을 배에 태운 경우
    if (remain <= 0)
    {
        // 출항하지 않은 배들의 수용 무게
        ans = totalWeight;
        return;
    }
    // 중복없는 순열
    for (int i = 0; i < B; i++)
    {
        if (visit[i])
            continue;
        int end = findBound(s, boat[i]);
        // 현재 배의 순서로 남은 인원을 한명도 태우지 못하는 경우
        if (end == -1)
            continue;
        visit[i] = 1;
        DFS(remain - (end - s), totalWeight - boat[i], end);
        visit[i] = 0;
    }
}

int main(void)
{
    scanf("%d %d", &B, &N);
    for (int i = 0; i < B; i++)
    {
        scanf("%d", boat + i);
        totalWeight += boat[i];
    }
    for (int i = 0; i < N; i++)
    {
        scanf("%d", passenger + i);
        psum[i + 1] = passenger[i] + psum[i];
    }
    // 수용할 수 있는 전체 무게보다 사람이 많은 경우
    if (psum[N] > totalWeight)
    {
        printf("-1");
        return 0;
    }
    DFS(N, totalWeight, 0);
    printf("%d", ans);
}

#include <stdio.h>
#include <stdlib.h>
int N;
int grids[500 + 10][500 + 10];
int visited[500 + 10][500 + 10]; //방문표시
int visitedcnt;                  //방문개수 파악용
int dh[] = {-1, 1, 0, 0};
int dw[] = {0, 0, -1, 1};
void InputData(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &grids[i][j]);
        }
    }
}
int FloodFill(int h, int w, int d, int half)
{
    visited[h][w] = d; //방문표시
    if (++visitedcnt >= half)
        return 1; //이미 절반 이상 돌아다녔음. 더 이상 할 필요없음
    for (int i = 0; i < 4; i++)
    {
        int nh = h + dh[i];
        int nw = w + dw[i];
        if ((nh < 0) || (nh >= N) || (nw < 0) || (nw >= N))
            continue; //범위 벗어남
        if (visited[nh][nw] == d)
            continue; //이미 방문 했음
        int diff = abs(grids[h][w] - grids[nh][nw]);
        if (diff > d)
            continue; //트랙터 힘보다 높이 차이가 더 크므로 갈수없음
        if (FloodFill(nh, nw, d, half))
            return 1; //성공이 리턴되면 성공 리턴
    }
    return 0; //실패
}
int isPossible(int d)
{
    //1.visited배열 초기화(d값으로 방문 표시하면 초기화 불필요)
    //2.탐색하면서 방문하지 않는 격자에서 출발시켜보기(절반이상 돌아다닐수 있으면 성공)
    int sum = 0, half = (N * N + 1) / 2;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (visited[i][j] == d)
                continue; //이번 체크시 방문했음. skip
            visitedcnt = 0;
            FloodFill(i, j, d, half);
            if (visitedcnt >= half)
                return 1; //절반이상 돌아다닐 수 있음. 성공
            sum += visitedcnt;
            if (sum > half)
                return 0; //실패한 격자 개수가 절반 이상이면 무조건 실패
        }
    }
    return 0; //실패
}
int Solve()
{
    //1.높이 중 최솟값과 최댓값 구하기
    int minv = (int)2e6, maxv = -1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (minv > grids[i][j])
                minv = grids[i][j]; //높이 중 최솟값
            if (maxv < grids[i][j])
                maxv = grids[i][j]; //높이 중 최댓값
        }
    }
    //2.이진탐색 가능한 D(힘)값 중 최솟값(lower bound)
    int s = 0, e = maxv - minv, sol = e;
    while (s <= e)
    {
        int m = (s + e) / 2;
        if (isPossible(m))
        {
            sol = m;
            e = m - 1;
        }
        else
        {
            s = m + 1;
        }
    }
    return sol;
}
int main(void)
{
    int ans = -1;
    InputData();         // 입력받는 부분
    ans = Solve();       // 여기서부터 작성
    printf("%d\n", ans); // 출력하는 부분
    return 0;
}
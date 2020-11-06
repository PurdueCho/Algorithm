#include <stdio.h>
#include <stdlib.h>
#define MAXN (100)
int A;            //초기 유저 물방울 크기
int N;            //물방울 개수
int W[MAXN + 10]; //물방울 크기
int sol;          //최소 스킬 개수
void InputData(void)
{
    scanf("%d %d", &A, &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &W[i]);
    }
}
void DFS(int n, int user, int skill)
{ //물방울 인덱스, 유저물방울크기, 사용스킬수
    if (sol <= skill)
        return; //가지치기, 중간답이 이전보다 안좋음
    if (n >= N)
    { //종료조건(모든 물방울 제거 함)
        sol = skill;
        return;
    }
    if (user > W[n])
    { //흡수 가능
        DFS(n + 1, user + W[n], skill);
    }
    else
    { //흡수 불가능 한 경우
        //1.생성
        if (user > 1)
        {
            DFS(n, user + user - 1, skill + 1);
        }
        //2.제거(n번째 제거하면 나머지 모두 제거)
        DFS(N, user, skill + N - n); //모두 제거이므로 물방울 크기 계산할 필요 없음
    }
}
int comp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int Solve(void)
{
    //1.오름차순 정렬
    qsort(W, N, sizeof(W[0]), comp);
    //2.DFS
    sol = N;
    DFS(0, A, 0); //물방울 인덱스, 유저물방울크기, 사용스킬수
    return sol;
}
int main(void)
{
    int t, T, ans = -1;
    scanf("%d", &T);
    for (t = 1; t <= T; t++)
    {
        InputData();                      //입력받는 부분
        ans = Solve();                    //여기서부터 작성
        printf("Case #%d: %d\n", t, ans); //출력하는 부분
    }
    return 0;
}
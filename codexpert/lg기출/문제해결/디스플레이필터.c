#include <stdio.h>
#define INF ((S64)1 << 60)
typedef long long S64;
int N;       // 필터의 수
int R[11];   // 반사의 정도
int P[11];   // 투과의 정도

S64 soldiff; //최적의 가시성(최솟값 절대값(반사곱-투과합))
int solcnt;  //최적의 가시성 일때 필터 개수(최소 남겨야함)

S64 ABS(S64 x) { return (x < 0) ? -x : x; }

int comp(S64 diff, int cnt)
{
    if (soldiff == diff)
        return solcnt > cnt;
    return soldiff > diff;
}

void DFSmulti(int s, int cnt, S64 mul, S64 sum)
{ //시작인덱스,  선택개수,  반사곱,  투과합
    if (cnt > 0)
    {                              //답 갱신
        S64 diff = ABS(mul - sum); //현재 경우의 가시성
        if (comp(diff, cnt))
        {
            soldiff = diff;
            solcnt = cnt;
        }
    }
    //경우의 수
    for (int i = s; i <= N; i++)
    {
        DFSmulti(i + 1, cnt + 1, mul * R[i], sum + P[i]);
    }
}

void DFSbt(int n, int cnt, S64 mul, S64 sum)
{ //필터인덱스,  선택개수,  반사곱,  투과합
    if (cnt > 0)
    {                              //답 갱신
        S64 diff = ABS(mul - sum); //현재 경우의 가시성
        if (comp(diff, cnt))
        {
            soldiff = diff;
            solcnt = cnt;
        }
    }
    if (n > N)
        return; //종료조건
    //경우의 수
    DFSbt(n + 1, cnt + 1, mul * R[n], sum + P[n]); //n번 필터 선택하는 경우
    DFSbt(n + 1, cnt, mul, sum);                   //n번 필터 선택 하지 않는 경우
}

int Solve()
{
    soldiff = INF;
    DFSmulti(1, 0, 1, 0); //시작인덱스,  선택개수,  반사곱,  투과합
    //DFSbt(1,  0,  1,  0);//필터인덱스,  선택개수,  반사곱,  투과합
    return N - solcnt; //총개수 - 남길개수 = 제거개수(최대한 많이 제거)
}

void InputData(void)
{
    int i;
    scanf("%d", &N);
    for (i = 1; i <= N; i++)
        scanf("%d %d", &R[i], &P[i]);
}

int main()
{
    int ans = -1;
    InputData();         // 입력함수
    ans = Solve();       // 코드를 작성 하세요
    printf("%d\n", ans); //출력
    return 0;
}
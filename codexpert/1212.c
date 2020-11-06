#include <stdio.h>
#include <stdlib.h>
#define MAXN (10)
#define MAXM (100)
int N, M;                     //직원수, 상하관계개수
int link[MAXN + 1][MAXN + 1]; //[상급자][하급자]=여부(1:YES, 0:NO)
int bonus[MAXN + 1];          //보너스금액
int used[MAXN + 1];           //보너스금액 지불 여부
int sol[MAXN + 1];            //실제지불
int isPossible(int n, int p)
{
    for (int i = 1; i <= N; i++)
    { //직원 인덱스
        if (n == i)
            continue; //본인임
        if (sol[i] == 0)
            continue; //판단불가, i번 직원은 아직 지급 전
        if ((link[n][i] == 1) && (sol[i] >= p))
            return 0; //n번 직원이 하급자 보다 많지 않음. 불가
        if ((link[i][n] == 1) && (sol[i] <= p))
            return 0; //n번 직원이 상급자 보다 적지 않음. 불가
    }
    return 1; //가능
}
int DFS(int n)
{ //직원 인덱스
    if (n > N)
        return 1; //모든 직원에게 보너스 위배 없이 지불, 성공
    for (int i = 2; i <= N; i++)
    { //보너스 인덱스
        if (used[i] == 1)
            continue; //i번 금액은 이미 지불 되었음
        if (!isPossible(n, bonus[i]))
            continue;      //n번 직원에게 i번 금액 지불 불가
        used[i] = 1;       //사용표시
        sol[n] = bonus[i]; //n번 직원에게 i금액 지불함
        if (DFS(n + 1) == 1)
            return 1; //성공했으면 리턴
        used[i] = 0;  //표시제거
        sol[n] = 0;   //
    }
    return 0; //실패
}
int comp(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}
void Solve()
{
    //1.bonus배열 내림차순 정렬
    qsort(&bonus[1], N, sizeof(bonus[0]), comp);
    //2.1번이 사장이므로 제일 큰 금액
    sol[1] = bonus[1];
    //2.2번 직원부터 모든경우(순열)
    DFS(2);
}
void InputData()
{
    int s, e;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &s, &e);
        link[s][e] = 1;
    }
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &bonus[i]);
    }
}
void OutputData()
{
    for (int i = 1; i <= N; i++)
    {
        printf("%d ", sol[i]);
    }
}
int main()
{
    InputData();
    Solve();
    OutputData();
    return 0;
}
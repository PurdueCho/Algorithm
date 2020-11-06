#include <stdio.h>
int N;          //직원 수
int M;          //기부금 총액
int A[1000010]; //직원 별 성과급
void Input_Data(void)
{
    int i;
    scanf("%d %d", &N, &M);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
}
int isPossible(int m)
{ //m(상한액),  m이하면 기부금 0원,  m초과하면 초과분이 기부금
    int sum = M;
    for (int i = 0; i < N; i++)
    {
        if (A[i] <= m)
            continue;
        sum -= A[i] - m;
        if (sum <= 0)
            return 1; //가능(M원 모으기 가능)
    }
    return 0; //불가능
}
int Solve()
{
    int s = 0, e = 0, sol = 0;
    //1.직원 성과급 중 max값 구하기(s(0) ~ e(max) 사이에 답이 존재)
    for (int i = 0; i < N; i++)
    {
        if (e < A[i])
            e = A[i];
    }
    //2.이진탐색 이용(upper bound 구하기,  상한액이 작을수록 기부금 커짐)
    while (s <= e)
    {
        int m = (s + e) / 2;
        if (isPossible(m))
        {
            sol = m;
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
    }
    return sol;
}
int main(void)
{
    int ans = 0;
    Input_Data();        //  입력 함수
    ans = Solve();       //    코드를 작성하세요
    printf("%d\n", ans); //  정답 출력
    return 0;
}
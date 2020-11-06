#include <stdio.h>
int N;              //LED 수
int S[100000 + 10]; //LED 상태
int A[100000 + 10];
void Input_Data(void)
{
    int i;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &S[i]);
    }
}
int Solve()
{
    //1.초기 ON/OFF패턴 구간 길이 구하기
    int cnt = 1;
    int n = 0;
    for (int i = 1; i < N; i++)
    {
        if (S[i] != S[i - 1])
            cnt++; //교차됨
        else
        {
            A[n++] = cnt;
            cnt = 1;
        }
    }
    A[n++] = cnt;
    //2.가운데 것을 반전시키면 앞뒤가 연결되므로 연속 3개를 더했을 때 가장 긴 구간 찾기
    if (n <= 3)
    { //구간이 3개 이하면 모두 연결됨
        return N;
    }
    int sum, maxsum;
    maxsum = sum = A[0] + A[1] + A[2];
    for (int i = 3; i < n; i++)
    {
        sum = sum - A[i - 3] + A[i]; //sliding window
        if (maxsum < sum)
            maxsum = sum;
    }
    return maxsum;
}
int main()
{
    int ans = -1;
    Input_Data();        //  입력 함수
    ans = Solve();       //    코드를 작성하세요
    printf("%d\n", ans); //  정답 출력
    return 0;
}
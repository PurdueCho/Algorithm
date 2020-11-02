#include <stdio.h>

int N;
int W[20];
int check[20];
int sol;

void InputData(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &W[i]);
    }
}

int validate(int cur, int next) {

    while( cur > 0 && next > 0 ) {  
        if ( (cur%10 + next%10) > 9 ){  // 각 자리의 수의 합이 자리올림 생기면
            return 0;
        }
        cur /= 10;
        next /= 10;
    }
    return 1; 
}

void DFS(int idx, int cur, int sum) {

    if (idx == N) {
        if (cur > sol) sol = cur;
        return;
    }

    printf("idx: %d, cur: %d, sum: %d\n", idx, cur, sum);
    if (validate(sum, W[idx])) {    // 가벼운 소
        check[idx] = 1;     // 방문처리
        DFS(idx+1, cur+1, sum+W[idx]);
        check[idx] = 0;
    }

    // 무거운소
    DFS(idx + 1, cur, sum);

}

void Solve()
{
    DFS(0, 0, 0);
}

int main(void)
{
    int ans = -1;

    InputData(); // 입력받는 부분

    // 여기서부터 작성
    Solve();
    ans = sol;

    printf("%d\n", ans); //출력하는 부분
    return 0;
}
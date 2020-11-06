#include <stdio.h>

int N; //직원 수
int S; //시작 직원 번호
int M;

#define MAXQ (1 << 16)
#define MOD (MAXQ - 1)
int queue[MAXQ];
int wp, rp;

void push(int n)
{
    queue[wp] = n;
    wp = (wp + 1) & MOD;
}
int front() { return queue[rp]; }
void pop() { rp = (rp + 1) & MOD; }
int empty() { return wp == rp; }

void solve()
{
    int i, j = S;
    for (i = 1; i <= N; i++)
    {
        push(j);
        if (++j > N)
            j = 1;
    }
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j < M; j++)
        {
            push(front());
            pop();
        }
        printf("%d ", front());
        pop();
    }
    printf("\n");
}

void InputData()
{
    scanf("%d %d %d", &N, &S, &M);
}
int main()
{

    InputData(); //  입력 함수

    //  코드를 작성하세요
    solve();

    return 0;
}
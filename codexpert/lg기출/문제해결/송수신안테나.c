#include <stdio.h>
int N;              //송수신 안테나 수
int H[100000 + 10]; //송수신 안테나 높이

//FA stack
int stack[100000 + 10];
int sp;
void push(int d) { stack[++sp] = d; }
void pop() { sp--; }
int top() { return stack[sp]; }
int empty() { return sp == 0; }
int size() { return sp; }

void InputData()
{
    int i;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &H[i]);
}

int Solve()
{
    int cnt = 0;
    sp = 0; //stack init
    for (int i = 0; i < N; i++)
    { //선택한 안테나 인덱스
        //1.스택에서 낮은 높이는 pop시키기 + 통신 가능 개수 증가
        while (!empty() && (top() < H[i]))
        {
            cnt++;
            pop();
        }
        //2.스택이 비어있지 않으면 통신 가능 개수 1 증가
        if (!empty())
        {
            cnt++;
            if (top() == H[i])
                pop(); //같은 높이 인 경우 제거
        }
        //3.i번 높이 안테나 스택에 저장
        push(H[i]);
    }
    return cnt;
}

int SolveN2()
{
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {              //선택한 안테나 인덱스
        int h = 0; //i랑 k 사이에 안테나 높이 중 가장 높은 높이
        for (int k = i + 1; k < N; k++)
        { //비교대상 안테나 인덱스
            if (h < H[k])
            {
                cnt++;
                h = H[k];
            }
            if (H[i] <= H[k])
                break; //가지치기
        }
    }
    return cnt;
}

int main()
{
    int ans = -1;
    InputData(); //  입력 함수

    //ans = SolveN2();//    코드를 작성하세요
    ans = Solve();

    printf("%d\n", ans); //출력
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define MAXN (20)

int N;
int sl, sr;
int M;
int seq[MAXN + 10];

int move = 999999;    // 이동 횟수

void InputData(void)
{
    scanf("%d", &N);            // 벽장 개수
    scanf("%d %d", &sl, &sr);   // 열린 벽장
    scanf("%d", &M);            // 이용 횟수
    for (int i = 0; i < M; i++) 
    {
        scanf("%d", &seq[i]);   // 이용 순서
    }
}

void DFS(int idx, int op1, int op2, int count) {

    if (idx == M) {
        if (count < move) move = count;
        return;
    }

    if (count > move) return;
    
    // 왼쪽 문
    DFS(idx + 1, seq[idx], op2, count + abs(seq[idx] - op1));
    // 오른쪽 문
    DFS(idx + 1, op1, seq[idx], count + abs(seq[idx] - op2));
}

void Solve() {

    DFS(0, sl, sr, 0);
}

int main(void)
{
    int ans = -1;

    InputData(); //입력받는 부분

    //여기서부터 작성

    Solve();
    ans = move;

    printf("%d\n", ans); //출력하는 부분
    return 0;
}
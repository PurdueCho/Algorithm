#include <stdio.h>
#include <stdlib.h>
#define MAXN ((int)1e5)

int N;
int X[MAXN + 10];
int Y[MAXN + 10];

typedef struct {
    int x, y;
} Node;

Node points[MAXN + 10];

int calculate(Node cur, Node next)
{
    int dist = 0;

    dist = abs(cur.x - next.x) + abs(cur.y - next.y);

    return dist;
}

void InputData(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &X[i], &Y[i]);
        Node n = {X[i], Y[i]};
        points[i] = n;
    }
}




int Solve() {
    int total = 0;
    for (int i = 0 ; i < N - 1 ; i ++) {
        total += calculate(points[i], points[i+1]);
    }
    //printf("Total: %d\n", total);

    Node prev;
    Node cur;
    Node next;

    int dist = 0;
    int jump = 0;
    int diff = 0;

    for (int i = 1 ; i < N - 1; i++) {
        prev = points[i-1];
        cur = points[i];
        next = points[i+1];

        dist = calculate(prev, cur) + calculate(cur, next);
        jump = calculate(prev, next);

        diff = (diff < dist - jump) ? dist-jump : diff;
    }

    return total - diff;
}


int main(void)
{
    int ans = -1;

    InputData(); //입력받는 부분

    //여기서부터 작성
    ans = Solve();

    printf("%d\n", ans); //출력하는 부분
    return 0;
}

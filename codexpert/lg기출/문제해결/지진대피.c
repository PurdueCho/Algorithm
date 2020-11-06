#include <stdio.h>

int N;           //자재박스의 개수
int Sx;          // 지게차의 최초 열위치
int Sy;          // 지게차의 최초 행위치
int BoxX[12000]; // 자재박스의 열위치
int BoxY[12000]; // 자재박스의 행위치

int map[500 + 10][500 + 10];
int weight[500 + 10][500 + 10];

typedef struct {
    int x, y, t;
} Node;

Node queue[500* 500* 10];
int front, rear;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void enQueue( Node n) {
    queue[rear++] = n;
}

Node deQueue () {
    return queue[front++];
}

int isEmpty() {
    if (front == rear) return 1;
    return 0;
}

void InputData(void)
{
    int i;
    scanf("%d %d %d", &N, &Sx, &Sy);
    for (i = 0; i < N; i++)
    {
        scanf("%d %d", &BoxX[i], &BoxY[i]);
        weight[BoxY[i]][BoxX[i]] = 1;
    }
}

int BFS() {

    Node cur;
    Node next;

    // 시작 지점
    cur.y = Sy;
    cur.x = Sx;
    cur.t = 0;

    map[cur.y][cur.x] = 1;
    enQueue(cur);

    while (!isEmpty()) {
        cur = deQueue();

        if (map[cur.y][cur.x] < cur.t) continue;

        for (int i = 0 ; i < 4 ; i++) {
            next.y = cur.y + dy[i];
            next.x = cur.x + dx[i];

            if (next.y < 0 || next.y > 501 || next.x < 0 || next.x > 501) {
                continue;
            }

            if (map[next.y][next.x] == 0 || map[cur.y][cur.x] + weight[next.y][next.x] < map[next.y][next.x]) {
                map[next.y][next.x] = map[cur.y][cur.x] + weight[next.y][next.x];
                next.t = map[next.y][next.x];
                enQueue(next);
            }
        }
    }

    return map[0][0] - 1;
}

int Solve() {
    int ret;
    ret = BFS();
    return ret;
}

int main(void)
{
    int ans = -1;
    InputData(); //	입력함수

    //	코드를 작성하세요
    ans = Solve();

    printf("%d\n", ans); //출력
    return 0;
}

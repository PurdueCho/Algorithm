#include <stdio.h>
#define MAXN (100)

typedef struct {
    int x, y, time;
}Zerg;

Zerg queue[MAXN * MAXN + 10];
int front = 0;
int rear = 0;

int X, Y;                       //지도의 가로 세로 크기
int map[MAXN + 10][MAXN + 10]; //지도 정보('1':저글링, '0':빈곳)
int sx, sy;                     //시작위치 가로 세로 좌표

int check[MAXN + 10][MAXN + 10];

int dx[4] = {0, 0, 1, -1 };     // 상하좌우
int dy[4] = {1, -1, 0, 0 };
int remain;

void InputData(void)
{
    scanf("%d %d", &X, &Y);

    for (int i = 1; i <= Y; i++) {
        for (int j = 1; j <= X; j++) {
            scanf("%1d", &map[i][j]);
            if (map[i][j] == 1) remain++;
        }
    }
    scanf("%d %d", &sx, &sy);
}

void enQueue(Zerg zerg) {
    queue[rear++] = zerg;
}

Zerg deQueue() {
    return queue[front++];
}

int isEmpty() {
    if (front == rear) return 1;
    return 0;
}

void printMap() {
    for (int i = 1; i <= Y; i++) {
        for (int j = 1; j <= X; j++) {
            printf("%d", check[i][j]);
        }
        printf("\n");
    }
}

int validation ( Zerg z) {
    if (z.x < 1 || z.y < 1 || z.x > X || z.y > Y) {
        return 0;
    }

    if (map[z.y][z.x] == 0) {
        return 0;
    }

    return 1;
}

int BFS() {
    Zerg cur;
    Zerg next;

    cur.x = sx;
    cur.y = sy;
    cur.time = 3;
    map[cur.y][cur.x] = 0;          // 탐색한(죽은) 저글링은 0 표시
    check[cur.y][cur.x] = cur.time;

    enQueue(cur);

    while (!isEmpty()) {
        cur = deQueue();

        for (int i = 0; i < 4 ; i++) {  // 4방향 탐색
            
            next.x = cur.x + dx[i];
            next.y = cur.y + dy[i];
            next.time = cur.time + 1;

            if (validation(next))
            {
                enQueue(next);
                map[next.y][next.x] = 0;
                check[next.y][next.x] = next.time;
            }
        }
    }

    return next.time-1;

} 

int Alive() {
    int count = 0;
    for (int i = 1 ; i <= Y ; i++) {
        for (int j = 1; j<= X ; j++) {
            if (map[i][j] == 1) {
                count++;
            }
        }
    }

    return count;
}


void Solve() {

    int time = BFS();
    int count = Alive();

    printf("%d %d\n", time, count);


}



int main(void)
{
    InputData(); //입력 받는 부분

    //여기서부터 작성
    //printMap();
    Solve();
    //printMap();

    return 0;
}
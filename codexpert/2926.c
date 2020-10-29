#include <stdio.h>
#include <stdlib.h>

#define MAXN (50)


int R, C; //지도 세로, 가로 크기
char map[MAXN + 10][MAXN + 10];
int convert[MAXN + 10][MAXN + 10];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

typedef struct {
    int type;   // 0: * , 1: S
    int x, y;
    int time;
} Node;

Node queue[MAXN*MAXN + 10];
int front;
int rear;

Node destination;

void enQueue( Node q ) {
    queue[rear++] = q;
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
    scanf("%d %d", &R, &C);
    for (int i = 0; i < R; i++) {
        scanf("%s", &map[i][0]);
    }
}

void testPrint() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C ; j++) {
            printf("%d", convert[i][j]);
        }
        printf("\n");
    }
}

void Init() {
    Node n;
    Node s;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (map[i][j] == '*')
            { // 홍수
                convert[i][j] = -1;
                n.type = 0;
                n.time = 1;
                n.y = i;
                n.x = j;
                enQueue(n);
            }
            if (map[i][j] == 'S') {
                convert[i][j] = -2;
                s.type = 1;
                s.time = 1;
                s.y = i;
                s.x = j;
            }
            if (map[i][j] == 'D') {
                convert[i][j] = -3;
                destination.type = 2;
                destination.y = i;
                destination.x = j;
            }
            if (map[i][j] == '.')
            {
                convert[i][j] = -4;
            }
        }
    }
    enQueue(s);
    
}

int validation (Node node) {
    if (node.y < 0 || node.x < 0 || node.y >= R || node.x >= C) {
        return 0;
    }

    if (map[node.y][node.x] != '.' ) {
        return 0;
    }

    return 1;
}

int Solve() {

    Init();

    Node cur;
    Node next;

    while (!isEmpty())
    {
        cur = deQueue();

        //printf("Type: %d, y: %d, x: %d\n", cur.type, cur.y, cur.x);

        for (int i = 0 ; i < 4 ; i ++ ) {
            next.type = cur.type;
            next.time = cur.time + 1;
            next.y = cur.y + dy[i];
            next.x = cur.x + dx[i];

            //printf("Next Type: %d\n", next.type);

            if (validation(next)) {
                
                enQueue(next);
                if (next.type == 1) {
                    map[next.y][next.x] = 'S';
                    convert[next.y][next.x] = next.time;
                } else {
                    map[next.y][next.x] = '*';
                    convert[next.y][next.x] = -1;
                }

            }
        }
    }

    // 시간 찾기
    int ny, nx;
    int time = 99999999;

    for (int i = 0; i < 4 ; i++) {
        ny = destination.y + dy[i];
        nx = destination.x + dx[i];

        // 사방 탐색
        if (ny >= 0 && ny < R && nx >= 0 && nx < C) {
            if (map[ny][nx] == 'S') {
                time = time < convert[ny][nx] ? time : convert[ny][nx];
                if (time == -2) {
                    time = 1;
                }
            }
        }
    }

    if (time != 99999999)
    {
        return time;
    }
    else
    {
        return -1;
    }
}

int main(void)
{
    int T, ans = -1;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++)
    {
        InputData(); //입력 받는 부분
        // 여기서부터 작성
        ans = Solve();

        //testPrint();

        if (ans == -1)
            printf("KAKTUS\n"); //출력 하는 부분
        else
            printf("%d\n", ans);
    }
    return 0;
}
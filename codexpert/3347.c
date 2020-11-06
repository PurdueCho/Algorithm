#include <stdio.h>
#define MAX_SIZE (30)

int L, R, C;
char map[MAX_SIZE + 10][MAX_SIZE + 10][MAX_SIZE + 10];  // L R C
int check[MAX_SIZE + 10][MAX_SIZE + 10][MAX_SIZE + 10];  // L R C

typedef struct {
    int l, y, x;
    int time;
} Node;

Node queue[MAX_SIZE * MAX_SIZE * MAX_SIZE + 10];
int front, rear;

int dy[6] = {1, -1, 0, 0, 0, 0};
int dx[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

void enQueue( Node n ) {
    queue[rear++] = n;
}

Node deQueue ( ) {
    return queue[front++];
}

int isEmpty() {
    if (front==rear) return 1;
    return 0;
}

int InputData(void)
{
    scanf("%d %d %d", &L, &R, &C);
    if ((L == 0) && (R == 0) && (C == 0))
        return 0;
    for (int l = 0; l < L; l++)
    {
        for (int r = 0; r < R; r++)
        {
            scanf("%s", map[l][r]);
        }
    }
    return 1;
}

int BFS( Node start, Node end) {
    int time = 99999999;
    enQueue(start);

    Node cur;
    Node next;

    while (!isEmpty()) {
        cur = deQueue();

        //printf("loc: l y x %d %d %d\n", cur.l, cur.y, cur.x);

        if (cur.l == end.l && cur.y == end.y && cur.x == end.x) {   // 도착
            //printf("hello\n");
            if (time > cur.time) {
                time = cur.time;
            }
        }

        for (int i = 0 ; i < 6 ; i++) {
            next.l = cur.l + dz[i];
            next.y = cur.y + dy[i];
            next.x = cur.x + dx[i];


            if (next.l < 0 || next.y < 0 || next.x < 0 || next.l > L || next.y > R || next.x > C) {
                continue;
            }

            if (check[next.l][next.y][next.x] == 1) {
                continue;
            }

            if (map[next.l][next.y][next.x] == '.' || map[next.l][next.y][next.x] == 'E') {
                check[next.l][next.y][next.x] = 1;
                next.time = cur.time + 1;
                enQueue(next);
            }


        }

    }

    return time;
}

int Solve() {

    Node start, end;
    int time;

    for (int l = 0 ; l < L ; l++) {
        for (int i = 0; i < R ; i++) {
            for (int j = 0 ; j < C ; j++) {
                if (map[l][i][j] == 'S') {
                    start.l = l;
                    start.y = i;
                    start.x = j;
                    start.time = 0;
                    //printf("start: l y x %d %d %d\n", start.l, start.y, start.x);
                } else if (map[l][i][j] == 'E') {
                    end.l = l;
                    end.y = i;
                    end.x = j;
                    //printf("end: l y x %d %d %d\n", end.l, end.y, end.x);
                }
            }
        }
    }

    time = BFS(start, end);

    if (time == 99999999) {
        return -1;
    }

    return time;

    //printf("min time %d\n", time);

}

void init() {
    front = 0;
    rear = 0;

    for (int l = 0; l < L; l++)
    {
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                check[l][i][j] = 0;
            }
        }
    }
}

int main(void)
{
    int ans = -1;
    while (InputData())
    {

        //여기서부터 작성
        init();

        ans = Solve();

        if (ans == -1)
            printf("Trapped!\n");
        else
            printf("Escaped in %d minute(s).\n", ans);
    }
    return 0;
}

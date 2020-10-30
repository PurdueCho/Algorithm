#include <stdio.h>
#define MAXN (100)

int N, M;
int map[MAXN + 10][MAXN + 10];
int check[MAXN + 10][MAXN + 10];

int hour, sol;

int status[MAXN];   // 남아있는 치즈

typedef struct {
    int y, x;
} Node;

Node queue[MAXN * MAXN];
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
    if (front == rear) {
        return 1;
    }
    return 0;
}

void InputData(void)
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
}

int BFS (int y, int x) {

    int count = 0;

    Node cur;
    Node next;

    cur.y = y;
    cur.x = x;

    enQueue(cur);

    while (!isEmpty()) {
        cur = deQueue();

        for (int i = 0 ; i < 4 ; i++) {
            next.y = cur.y + dy[i];
            next.x = cur.x + dx[i];
            if (next.y < 0 || next.x < 0 || next.y > N -1 || next.x > M -1) {
                continue;
            }   

            if (check[next.y][next.x] != 0) {
                continue;
            }

            if (map[next.y][next.x] == 1) {     // 치즈
                
                map[next.y][next.x] = 0;
                count++;
            } else {
                enQueue(next);
            }
            check[next.y][next.x] = 1;
        }
    }

    return count;
}

void testPrint()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%d", map[i][j]);
        }
        printf("\n");
    }
}

void Init() {
    front = 0, rear = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            check[i][j] = 0;
        }
    }
}

int Solve() {

    int count = 999999;
    int time = 0;

    while (count > 0) {
        Init();
        count = BFS(0, 0);
        status[time++] = count;
        // printf("count: %d\n", count);
        // testPrint();
    }

    return time - 1;
}



int main(void)
{
    InputData(); // 입력받는 부분

    // 여기서부터 작성
    //testPrint();
    hour = Solve();
    sol = status[hour-1];

    

    printf("%d\n%d\n", hour, sol); // 출력하는 부분
    return 0;
}

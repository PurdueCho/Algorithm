#include <stdio.h>

int N;
int X[10000 + 10];
int Y[10000 + 10];

int map[100+10][100+10];
int check[100+10][100+10];
int cnt[100 + 10][100 + 10];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};

typedef struct {
    int y, x;
}Node;

Node queue[110 * 110 * 110];
int front, rear;

void enQueue(Node n) {
    queue[rear++] = n;
}

Node deQueue() {
    return queue[front++];
}

int isEmpty() {
    if (front == rear) return 1;
    return 0;
}

void InputData(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &X[i], &Y[i]);
        map[Y[i]][X[i]] = 1;    // 건초 표시
    }
}

void printTest() {
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0 ;j < 100; j++)
        {
            printf("%d", map[i][j]);
        }
        printf("\n");
    }
}


int BFS (int y, int x) {

    Node cur;
    Node next;

    cur.y = y;
    cur.x = x;

    enQueue(cur);

    int count = 0;

    while (!isEmpty()) {
        cur = deQueue();

        for (int i = 0 ; i < 4 ; i++) {
            next.y = cur.y + dy[i];
            next.x = cur.x + dx[i];

            if (next.y < 0 || next.x < 0 || next.y > 101 || next.x > 101) {
                continue;
            }

            if (check[next.y][next.x] == 1) {
                continue;
            }

            if (map[next.y][next.x] == 1) {
                count++;
            } else {
                enQueue(next);
                check[next.y][next.x] = 1;
            }
        }
    }
    
    return count;
}

int Solve() {
    int hay_perimeter;

    hay_perimeter = BFS(0, 0);

    return hay_perimeter;
}


int main(void)
{
    int ans = -1;

    InputData(); // 입력받는 부분

    // 여기서부터 작성
    //printTest();
    ans = Solve();

    printf("%d\n", ans); // 출력하는 부분
    return 0;
}
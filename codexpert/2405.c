#include <stdio.h>
#define MAXN (1000)

int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
typedef struct {
    int y, x, cost;
} Node;

Node queue[MAXN * MAXN * 8];
int front, rear;

int H, W;
char map[MAXN + 10][MAXN + 10];
int ans;

void enQueue ( Node n ) {
    queue[rear++] = n;
}

Node deQueue () {
    return queue[front++];
}

int isEmpty() {
    if (front==rear) return 1;
    return 0;
}

void InputData(void)
{
    scanf("%d %d", &H, &W);
    for (int i = 0; i < H; i++)
    {
        scanf("%s", map[i]);
        for (int j = 0; j < W; ++j) {
            if (map[i][j] == '.') {
                Node node = {i, j, 0};
                enQueue(node);
            }
        }
    }
}

void BFS() {
    Node cur;
    Node next;

    while (!isEmpty()) {
        
        cur = deQueue();

        for (int i = 0; i < 8; ++i) {
            next.x = cur.x + dx[i];
            next.y = cur.y + dy[i];

            if (next.x < 0 || next.y < 0 || next.x >= W || next.y >= H)
                continue;
            
            if (map[next.y][next.x] == '.' || map[next.y][next.x] == '9')
                continue;

            if (--map[next.y][next.x] == '0')
            {
                next.cost = cur.cost + 1;
                enQueue(next);

                ans = (ans < next.cost) ? next.cost : ans;
            }
        }
    }
}

void Solve() {
    BFS();
}


int main(void)
{
    

    InputData(); //입력받는 부분

    //여기서부터 작성
    Solve();

    printf("%d\n", ans); //출력하는 부분
    return 0;
}
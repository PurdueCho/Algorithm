#include <stdio.h>
#include <stdlib.h>

#define MAX (100)
int M, N, K; //세로크기, 가로크기, 직사각형 개수
int sx[MAX + 10];
int sy[MAX + 10];
int ex[MAX + 10];
int ey[MAX + 10];

int sol[MAX * MAX]; //각 영역 넓이 저장용

typedef struct {
    int y, x;
} Node;

Node queue[MAX*MAX + 10];
int front, rear;

int map[MAX + 10][MAX + 10];
int check[MAX + 10][MAX + 10];

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};

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

void InputData()
{
    scanf("%d %d %d", &M, &N, &K);
    for (int i = 0; i < K; i++)
    {
        scanf("%d %d %d %d", &sx[i], &sy[i], &ex[i], &ey[i]);
    }
}
void OutputData(int ans)
{
    printf("%d\n", ans);
    for (int i = 0; i < ans; i++)
    {
        printf("%d ", sol[i]);
    }
    printf("\n");
}

void Init() {
    
    for (int i = 0 ; i < K ; i++) {
        
        for (int y = sy[i] ; y < ey[i]; y++ ) {
            for (int x = sx[i]; x < ex[i] ; x++) {
                map[y][x] = 1;
            }
        }
    }
}

void testPrint() {
    for (int i = 0 ; i < M ; i++) {
        for (int j = 0 ; j < N; j++) {
            printf("%d", map[i][j]);
        }
        printf("\n");
    }
}

int BFS ( int y, int x) {

    int count = 1;

    Node cur;
    Node next;

    cur.y = y;
    cur.x = x;

    enQueue(cur);
    check[cur.y][cur.x] = 1;
    //printf("count: %d, %d %d\n", count, cur.x, cur.y);

    while (!isEmpty()) {
        cur = deQueue();

        for (int i = 0 ; i < 4 ; i++) {
            next.y = cur.y + dy[i];
            next.x = cur.x + dx[i];

            if (next.y < 0 || next.x < 0 || next.y > M - 1 || next.x > N - 1) {
                continue;
            }

            if (check[next.y][next.x]) {
                continue;
            }

            if (map[next.y][next.x] == 0) {
                count++;
                enQueue(next);
                check[next.y][next.x] = 1;
                //printf("count: %d, %d %d\n", count, next.x, next.y);
            }

        }
    }

    return count;

}

int Solve() {
    int count = 0;
    int idx = 0;

    for (int i = 0 ; i < M ; i++) {
        for (int j = 0 ; j < N; j++) {
            if(map[i][j] == 0 && check[i][j] == 0) {
                count = BFS(i, j);
                sol[idx++] = count;
            }
        }
    }
    return idx;
}

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main(void)
{
    int ans = -1;
    InputData(); //입력받는 부분

    //여기서부터 작성
    Init();
    //testPrint();
    ans = Solve();
    qsort(sol, ans, sizeof(int), compare);

    OutputData(ans); //출력하는 부분
    return 0;
}
#include <stdio.h>
#define MAXN (100)
int N;
int K;
int R[MAXN + 10];
int C[MAXN + 10];
int L;

int X[MAXN + 10];
char CMD[MAXN + 10];

int map[MAXN + 10][MAXN + 10];

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

typedef struct {
    int y, x;
} Node;

Node queue[MAXN * MAXN + 10];
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
    scanf("%d", &K);

    for (int i = 0; i < K; i++)
    {
        scanf("%d %d", &R[i], &C[i]);
        map[R[i] - 1][C[i] - 1] = 1;    // 과일 위치
    }

    scanf("%d", &L);
    for (int i = 0; i < L; i++)
    {
        scanf("%d %c", &X[i], &CMD[i]);
    }
}

void testPrint() {
    for (int i = 0 ; i < N; i ++) {
        for (int j = 0 ; j < N ; j++) {
            printf("%d", map[i][j]);
        }
        printf("\n");
    }
}

int Solve() {
    
    Node next;
    // 처음 뱀 위치
    Node head = {0 , 0}; //  뱀 머리
    enQueue(head);
    map[head.y][head.x] = 2;

    int cur_dir = 0;        // 현재 방향
    int dir_time = 0;       // 시간
    char dir;               // 진행방향
    int idx = 0;            // 커맨드 인덱스
    int time = 0;           // 게임 시간

    while (1) {
        time ++;
        // printf("Time %d \n", time);
        next.y = head.y + dy[cur_dir];
        next.x = head.x + dx[cur_dir];

        if (next.y < 0 || next.x < 0 || next.y >= N || next.x >= N)
        {
            break;
        }

        if (map[next.y][next.x] == 2) {    // 머리가 몸통에 부딪힘
            break;
        }

        if (map[next.y][next.x] != 1) {     // 과일 없음 몸통 이동
            Node body = deQueue();
            map[body.y][body.x] = 0;
        }

        // 머리 이동
        map[next.y][next.x] = 2;
        head = next;
        enQueue(head);

        // 커맨드 갱신
        dir_time = X[idx];

        if (idx < L && dir_time == time)    // 방향 전환 시간
        {
            dir = CMD[idx];
            if (dir == 'L') {
                cur_dir = (cur_dir+3) % 4;
            } else if (dir == 'D')
            {
                cur_dir = (cur_dir+1) % 4;
            }
            idx++;
        }
        // testPrint();
        // printf("\n");
    }

    

    return time;

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
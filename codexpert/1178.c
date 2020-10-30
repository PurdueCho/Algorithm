#include <stdio.h>
#define MAXN (102)

int N;      //산크기
int eh, ew; //정상 위치 세로, 가로
int map[MAXN][MAXN];
int eMap[MAXN][MAXN];

int dy[4] = {1, -1, 0 , 0};
int dx[4] = {0, 0, -1, 1};

typedef struct {
    int y, x;
    int height;
    int energy;
} Node;

Node queue[1000000];
int front, rear;

void enQueue(Node q)
{
    queue[rear++] = q;
}

Node deQueue () {
    return queue[front++];
}

int isEmpty() {
    if (front == rear ) {
        return 1;
    }
    return 0;
}


void InputData(void)
{
    scanf("%d", &N);
    scanf("%d %d", &eh, &ew);
    for (int y = 1; y <= N; y++)
    {
        for (int x = 1; x <= N; x++)
        {
            scanf("%d", &map[y][x]);
        }
    }
}

void testPrint() {
    for (int i = 0; i <= N + 1 ; i++) {
        for (int j = 0; j <= N + 1; j++) {
            printf("%d ", eMap[i][j]);
        }
        printf("\n");
    }
}

int Solve() {
    Node cur;
    Node next;
    int min = 9999999;
    int temp;

    for (int i = 1; i <= N ; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            eMap[i][j] = 999999;
        }
    }

    for (int i = 0; i <= N + 1; i++)
    {
        for (int j = 0; j <= N + 1; j++)
        {
            if (eMap[i][j] == 0) {
                Node n = {i, j, 0, 0};
                enQueue(n);
            }
        }
    }

    while (!isEmpty())
    {
        cur = deQueue();

        for (int j = 0; j < 4; j++)
        {
            next.y = cur.y + dy[j];
            next.x = cur.x + dx[j];

            int temp;

            //printf("next : %d %d\n", next.x, next.y);

            if (next.y >= 1 && next.x >= 1 && next.y <= N && next.x <= N) {
                // 등반 조건
                next.height = map[next.y][next.x];
                if (cur.height < next.height)
                { // 올라감 높이의 차의 제곱
                    temp = cur.energy + (next.height - cur.height) * (next.height - cur.height);
                }
                else if (cur.height > next.height)
                { // 내려감 높이의 차
                    temp = cur.energy + (cur.height - next.height);
                }
                else
                { // 평지 힘 x
                    temp = cur.energy;
                }

                if (temp < eMap[next.y][next.x])
                {
                    eMap[next.y][next.x] = temp;
                    next.energy = temp;
                    enQueue(next);
                }
            }

            
        }
    }

    // return min;
    return eMap[eh][ew];

}

int main(void)
{
    int ans = -1;
    InputData(); //입력 받는 부분

    //여기서부터 작성
    ans = Solve();
    //testPrint();

    printf("%d\n", ans); //출력하는 부분
    return 0;
}
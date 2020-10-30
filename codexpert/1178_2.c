#include <stdio.h>
#include <math.h>
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

Node queue[999999*5];
int front, rear;

void enQueue(Node q)
{
    queue[rear++] = q;
}

Node deQueue () {
    return queue[front++];
}

int isFull() 
{
    if((rear+1)%MAXN == front)
    {
        return 1;
    }
    return 0;
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
    for (int i = 0; i <= N +1 ; i++) {
        for (int j = 0; j <= N +1; j++) {
            printf("%d ", eMap[i][j]);
        }
        printf("\n");
    }
}


int validation(Node n) {

    if (n.y < 0 || n.x < 0 || n.y > N +1 || n.x > N+1 ) {
        return 0;
    }

    return 1;
}


int Solve() {
    Node cur;
    Node next;
    int min = 9999999;
    int temp;

    for (int i = 0 ; i <= N + 1; i++) {
        for (int j = 0 ; j <= N + 1; j++) {
            eMap[i][j] = 999999;
        }
    }

    // 정상
    cur.y = eh;
    cur.x = ew;
    cur.height = map[eh][ew];
    cur.energy = 0;

    enQueue(cur);
    
    while (!isEmpty()) {
        cur = deQueue();

        if (cur.y < 1 || cur.y > N || cur.x < 1 || cur.x > N)
        {
            if (eMap[cur.y][cur.x] != 0) {
                min = (min < cur.energy) ? min : cur.energy;
            }
            continue;
        }

        for (int i = 0 ;i < 4; i++ ) {
            next.y = cur.y + dy[i];
            next.x = cur.x + dx[i];
            next.height = map[next.y][next.x];

            int temp;

            // 등반 조건
            if (cur.height < next.height)   // 내려감 
            {
                temp = cur.energy + (cur.height - next.height);
                
            }
            else if (cur.height > next.height)  // 올라감
            { 
                temp = cur.energy + (next.height - cur.height) * (next.height - cur.height);
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
            //printf("Check\n");   
        }
    }

    return min;
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
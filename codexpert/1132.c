#include <stdio.h>
#define MAXN (100)

int N; //그림크기(정사각형)
char map[MAXN + 10][MAXN + 10];
int check[MAXN + 10][MAXN + 10];
int col[MAXN + 10][MAXN + 10];
int sol1, sol2;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

typedef struct {
    int y, x;
} Node;

Node queue[MAXN * MAXN * MAXN];
int front, rear;

int area;

void enQueue (Node n) {
    queue[rear++] = n;
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
    scanf("%d", &N);
    for (int h = 0; h < N; h++)
    {
        scanf("%s", map[h]);
    }

}

void testPrint() {
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < N ; j++) {
            printf("%d", col[i][j]);
        }
        printf("\n");
    }
}

int BFS( int y, int x ) {
    front = 0;
    rear = 0;

    int count = 1;

    Node cur;
    Node next;

    cur.y = y;
    cur.x = x;
    //printf("cur col: %d\n", cur.type);

    enQueue(cur);
    check[cur.y][cur.x] = 1;
    
    while (!isEmpty()) {
        cur = deQueue();
        
        for (int i = 0 ; i < 4 ; i++) {
            next.y = cur.y + dy[i];
            next.x = cur.x + dx[i];

            if (next.y < 0 || next.x < 0 || next.y > N +1 || next.x > N +1)
            {
                continue;
            }

            if (check[next.y][next.x] == 1)
            {
                continue;
            }

            if (col[next.y][next.x] == col[cur.y][cur.x]) { 
                enQueue(next);
                check[next.y][next.x] = 1;
                count++;
            }
        }
        
    }

    area++;

    //printf("area %d color: %d %d\n", area, col[cur.y][cur.x], count);
    
    return count;

}


int Solve() {

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] == 'R')
            {
                col[i][j] = 1;
            }
            else if (map[i][j] == 'G')
            {
                col[i][j] = 2;
            }
            else
            {
                col[i][j] = 3;
            }
        }
    }

    int count = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (check[i][j] == 0) {
                BFS(i,j);
            }
            //printf("col %d count %d\n", col[i][j], count);
        }
    }
    return area;
}

int Solve2()
{
    area = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            check[i][j] = 0;
            if (map[i][j] == 'R')
            {
                col[i][j] = 1;
            }
            else if (map[i][j] == 'G')
            {
                col[i][j] = 1;
            }
            else
            {
                col[i][j] = 3;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (check[i][j] == 0) {
                BFS(i, j);
                
            }
            //printf("col %d count %d\n", col[i][j], count);
        }
    }

    return area;
}

int main(void)
{
    InputData(); // 입력받는 부분

    // 여기서부터 작성
    //testPrint();
    sol1 = Solve();
    sol2 = Solve2();

    printf("%d %d", sol1, sol2); // 출력하는 부분
    return 0;
}
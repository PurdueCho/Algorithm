#include <stdio.h>

int N;
int map[25 + 10][25 + 10];
int chk[25 + 10][25 + 10];

int cnt;
int sol[25 * 25 + 10];

int dx[] = {-1,1,0,0};
int dy[] = {-0,0,1,-1};

int house = 0;

void DFS (int x, int y) {
    if (map[y][x] != 1) return;

    map[y][x] = 0;
    house++;

    for (int i = 0; i<4; i++){
        DFS(y+dy[i], x+dx[i]);
    }
}

int main(void)
{
    int i, j;

    // 입력받는 부분
    scanf("%d", &N);
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            scanf("%1d", &map[i][j]);
        }
    }

    // 여기서부터 작성

    for (i = 1; i <= N ; i++) {
        for (j = 1 ; j <= N; j++) {
            if (map[i][j] == 1) {
                house = 0;
                DFS(i, j);
                sol[cnt++] = house;
            }
        }
    }

    // 출력하는 부분
    printf("%d\n", cnt);
    for (i = 0; i < cnt; i++)
    {
        printf("%d\n", sol[i]);
    }

    return 0;
}
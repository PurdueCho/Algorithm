#include <stdio.h>

int N;
int A[100 + 10];
int B[100 + 10];

int map[100+10][100+10];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int init;

void InputData(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &A[i], &B[i]);
        for (int x = A[i] ; x < A[i] + 10 ; x++) {
            for (int y = B[i] ; y < B[i]+10 ; y++) {
                map[x][y] = 1;
            }
        }
    }
}

void printMap() {
    for (int i = 0 ; i < 100; i++) {
        for (int j = 0 ; j < 100 ; j++) {
            printf("%d", map[i][j]);
        }
        printf("\n");
    }
}

int Solve() {
    int ret = 0;

    for (int i = 0 ; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (map[i][j] == 1) {
                for (int k = 0 ; k < 4; k++) {
                    if (map[i+dx[k]][j+dy[k]] == 0) ret++;
                }
            }
        }
    }
    //printf("%d\n", ret);

    return ret;
}

int main(void)
{
    int ans = -1;

    InputData(); // 입력받는 부분

    // 여기서부터 작성
    //printMap();
    ans = Solve();

    printf("%d\n", ans); // 출력하는 부분
    return 0;
}
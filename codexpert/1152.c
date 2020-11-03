#include <stdio.h>
#define MAXN (9)

int sudoku[MAXN][MAXN];
int sol[MAXN][MAXN];

int zero_cnt;

typedef struct {
    int y, x;
} Node;

Node node[MAXN * MAXN + 10];

void InputData(void)
{
    for (int r = 0; r < MAXN; r++)
    {
        for (int c = 0; c < MAXN; c++)
        {
            scanf("%d", &sudoku[r][c]);
            if (sudoku[r][c] == 0) {
                node[zero_cnt].y = r;
                node[zero_cnt].x = c;
                zero_cnt++;
            }
        }
    }
}

void OutputData(void)
{
    for (int r = 0; r < MAXN; r++)
    {
        for (int c = 0; c < MAXN; c++)
        {
            printf("%d ", sol[r][c]);
        }
        printf("\n");
    }
}

int validate ( int x, int y, int z) {

    // 가로세로 체크
    for (int i = 0 ; i < MAXN ; i++) {
        if (sudoku[i][x] == z || sudoku[y][i] == z) {
            return 0;
        }
    }

    // 구간 체크
    int _y = (y/3)*3;
    int _x = (x/3)*3;
    for (int i = 0 ; i < 3; i++){
        for (int j = 0 ; j < 3 ; j++) {
           if (sudoku[i + _y][j + _x] == z) {
               return 0;
           }
        }
    }

    return 1;
}

int flag = 0;
void DFS( int idx ) {
    
    if (idx == zero_cnt) {
        // 조건 통과?
        for (int i = 0 ; i < MAXN ; i++) {
            for (int j = 0 ; j < MAXN ; j++) {
                sol[i][j] = sudoku[i][j];
            }
        }
        flag = 1;
        return;
    }

    int y = node[idx].y;
    int x = node[idx].x;
    int arr[MAXN] = { 0, };
    int _i = 0;

    // 가능한 수 찾기
    for (int i = 1; i <= MAXN; i++)
    {
        if (validate(x, y, i))
        {
            arr[_i++] = i;
        }
    }

    if (_i == 0) return;    // 가지치기

    for (int i = 0 ; i < _i ; i++) {
        //printf("(x,y): (%d, %d) num: %d\n", x, y, arr[i]);
        if (flag == 1) return;  // 가지치기

        sudoku[y][x] = arr[i];
        DFS(idx + 1);
        sudoku[y][x] = 0;
    }

    // for (int i = 1 ; i <= MAXN ; i++) {
    //     if (validate(x, y, i)) {
    //         //printf("(x,y): (%d, %d) num: %d\n", x, y, i);
    //         sudoku[y][x] = i;
    //         DFS(idx + 1);
    //         sudoku[y][x] = 0;
    //     }
    // }


}

void Solve() {
    //printf("zero: %d\n", zero_cnt);
    DFS(0);

}
int main(void)
{
    InputData(); //입력받는 부분

    //여기서부터 작성
    Solve();

    OutputData(); //출력하는 부분
    return 0;
}

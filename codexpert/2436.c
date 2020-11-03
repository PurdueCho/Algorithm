#include <stdio.h>
#include <stdlib.h>
#define MAXH (5)
#define MAXW (9)

char map[MAXH + 2][MAXW + 2];
int solremain, solmove;

int dy[4] = {1, -1 ,0, 0};
int dx[4] = {0, 0, -1, 1};

int count;
int sol;

void InputData(void)
{
    for (int h = 0; h < MAXH; h++)
    {
        scanf("%s", &map[h][0]);
    }
}

void DFS (int idx) {

    for (int i = 0 ; i < MAXH; i++) {
        for (int j = 0 ; j < MAXW ; j++) {
            if (map[i][j] == 'o') {
                for (int k = 0 ; k < 4 ; k++) {
                    int next_y = i + dy[k];
                    int next_x = j + dx[k];

                    if (next_y < 0 || next_y >= 5 || next_x < 0 || next_x >= 9)
                        continue;
                    
                    if (map[next_y][next_x] == 'o') {
                        int nnext_y = next_y + dy[k];
                        int nnext_x = next_x + dx[k];

                        if (nnext_y < 0 || nnext_y >= 5 || nnext_x < 0 || nnext_x >= 9)
                            continue;

                        if (map[nnext_y][nnext_x] == '.') {
                            map[i][j] = '.';
                            map[next_y][next_x] = '.';
                            map[nnext_y][nnext_x] = 'o';
                            DFS (idx + 1);
                            map[i][j] = 'o';
                            map[next_y][next_x] = 'o';
                            map[nnext_y][nnext_x] = '.';
                        }
                    }
                }
            }
        }
    }

    sol = (idx > sol) ? idx : sol;

    return;

}

void Solve() {

    DFS(0);

}

int main(void)
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++)
    {
        InputData(); //입력받는 부분

        //여기서부터 작성
        count = 0;
        sol = 0;

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 9; j++) {
                if (map[i][j] == 'o')
                    count++;
            }
        }

        Solve();

        solremain = abs(count - sol);
        solmove = sol;

        printf("%d %d\n", solremain, solmove); //출력하는 부분
    }
    return 0;
}
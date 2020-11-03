#include <stdio.h>
char map[5][10];
char sol[5][10];
int visited[15];

typedef struct {
    int y, x;
} Node;

Node node[15];
int count;

void InputData(void)
{
    for (int h = 0; h < 5; h++)
    {
        scanf("%s", map[h]);
    }

    for (int i = 0 ; i < 5 ; i++) {
        for (int j = 0 ; j < 10 ; j++) {
            if (map[i][j] >= 'A' && map[i][j] <= 'L') {
                visited[map[i][j]-'A'] = 1;
            } else if (map[i][j] == 'x') {
                node[count].y = i;
                node[count].x = j;
                count++;
            }
        }
    }
}

void OutputData(void)
{
    for (int h = 0; h < 5; h++)
    {
        printf("%s\n", sol[h]);
    }
}

int validation () {
    if ((map[0][4] - 'A' + 1) + (map[1][3] - 'A' + 1) + (map[2][2] - 'A' + 1) + (map[3][1] - 'A' + 1) != 26)
        return 0;
    if ((map[0][4] - 'A' + 1) + (map[1][5] - 'A' + 1) + (map[2][6] - 'A' + 1) + (map[3][7] - 'A' + 1) != 26)
        return 0;
    if ((map[1][1] - 'A' + 1) + (map[1][3] - 'A' + 1) + (map[1][5] - 'A' + 1) + (map[1][7] - 'A' + 1) != 26)
        return 0;
    if ((map[3][1] - 'A' + 1) + (map[3][3] - 'A' + 1) + (map[3][5] - 'A' + 1) + (map[3][7] - 'A' + 1) != 26)
        return 0;
    if ((map[4][4] - 'A' + 1) + (map[3][3] - 'A' + 1) + (map[2][2] - 'A' + 1) + (map[1][1] - 'A' + 1) != 26)
        return 0;
    if ((map[4][4] - 'A' + 1) + (map[3][5] - 'A' + 1) + (map[2][6] - 'A' + 1) + (map[1][7] - 'A' + 1) != 26)
        return 0;
    
    return 1;
}

int flag = 0;
void DFS( int idx ) {
    if (flag == 1) return;

    if (idx == count) {
        if (validation()) {
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    sol[i][j] = map[i][j];
                }
            }
            flag = 1;
            return;
        }
    }

    for (int i = 0 ; i < 12; i++) {
        if (visited[i]) continue;

        int y = node[idx].y;
        int x = node[idx].x;

        visited[i] = 1;
        map[y][x] = i + 'A';
        DFS(idx + 1);
        map[y][x] = 'x';
        visited[i] = 0;

    }

}

void Solve() {

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
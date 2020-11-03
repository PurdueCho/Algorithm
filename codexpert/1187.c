#include <stdio.h>
#define MAXN (6)

int map[MAXN + 10][3];
int sol[4 + 10];

int team1[15 + 10]; //6C2
int team2[15 + 10];
int match[MAXN + 10][3];    // 승 무 패 0 1 2
int ret;

void InputData(void)
{
    for (int i = 0; i < MAXN; i++)
    {
        scanf("%d %d %d", &map[i][0], &map[i][1], &map[i][2]);  // 승 무 패 0 1 2
        for (int j = 0 ; j < 3; j++) {
            match[i][j] = 0;        // 초기화
        }
    }
}

void OutputData(void)
{
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", sol[i]);
    }
    printf("\n");
}

void Init() {
    int idx = 0;
    for (int i = 0 ; i < MAXN ; i++) {
        for (int j = i + 1; j < MAXN ; j++) {
            team1[idx] = i;
            team2[idx] = j;
            idx++;
        }
    }

    // for (int i = 0 ; i < idx; i++) {
    //     printf("Team1: %d Team2: %d\n", team1[i], team2[i]);
    // }
}

void DFS(int idx) {

    if (idx == 15) {
        for (int i = 0 ; i < MAXN ; i++) {
            for (int j = 0 ; j < 3 ; j++) {
                if (match[i][j] != map[i][j]) return;
            }
        }
        ret = 1;
        //printf("match: %d, map: %d\n", match[i][j], map[i][j]);
        return;

    }

    int p1 = team1[idx];
    int p2 = team2[idx];

    // 승 무 패 0 1 2
    // 승 패
    match[p1][0]++;
    match[p2][2]++;
    DFS(idx + 1);
    match[p1][0]--;
    match[p2][2]--;

    // 무 무
    match[p1][1]++;
    match[p2][1]++;
    DFS(idx + 1);
    match[p1][1]--;
    match[p2][1]--;

    // 패 승
    match[p1][2]++;
    match[p2][0]++;
    DFS(idx + 1);
    match[p1][2]--;
    match[p2][0]--;

}

void Solve() {
    int cnt_win = 0, cnt_draw = 0, cnt_lose = 0;

    for (int i = 0 ; i < MAXN; i++) {
        cnt_win += map[i][0];
        cnt_draw += map[i][1];
        cnt_lose += map[i][2];
    }

    if (cnt_win != cnt_lose || cnt_win > 15 || cnt_lose > 15 || cnt_win + cnt_draw + cnt_lose != 30) {
        return;
    }

    DFS(0);

}

int main(void)
{
    int i, ans = -1;

    Init(); // Match Gen. 6C2

    for (i = 0; i < 4; i++)
    {
        InputData(); // 입력받는 부분

        // 여기서부터 작성
        Solve();
        sol[i] = ret;
        ret = 0;
    }

    OutputData(); // 출력하는 부분
    return 0;
}
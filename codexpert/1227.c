#include <stdio.h>
#include <stdlib.h>

int w, h, n;
int dir[100 + 10];
int len[100 + 10];

int min;

int loc[100 + 10];

void InputData(void)
{
    scanf("%d %d", &w, &h);
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
    {
        scanf("%d %d", &dir[i], &len[i]);
        if (dir[i] == 1) {
            loc[i] = len[i];
        } else if (dir[i] == 2) {
            loc[i] = w + h + (w - len[i]);
        } else if (dir[i] == 3) {
            loc[i] = w + h + w + (h - len[i]);
        } else {
            loc[i] = w + len[i];
        }
    }
}



int Solve() {

    int dist = 0;
    int min = 0;

    for (int i = 0; i < n; i++) {
        dist = abs(loc[n] - loc[i]);    // 거리
        if (dist > 2*(w+h) - dist) {
            dist = 2 * (w + h) - dist;
        } else {
            ;
        }
        min += dist;

    }

    return min;
}

int main(void)
{
    int ans = -1;

    InputData(); // 입력받는 부분

    // 여기서부터 작성
    ans = Solve();

    printf("%d\n", ans); // 출력하는 부분
    return 0;
}